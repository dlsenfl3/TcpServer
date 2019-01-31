//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TcpThreadU.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TcpThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TTcpThread::TTcpThread(TApplicationInfo *a_pAppInfo)
	: TThread(true)		// false 이면 생성된 직후에 바로 실행.  false로 실행할때 Suspended = false로 두면
{						   	// 실행중인 상태로 인식  Error발생.
	m_pAppInfo = a_pAppInfo;
	IdUDPServerThr = new TIdUDPServer();
	IdUDPServerThr->OnUDPRead = IdUDPServerThrUDPRead;

	Priority 		= tpNormal;
	FreeOnTerminate = true;                            //	스레드가 Terminate할때 자동으로 파괴할지를 결정하는 property
	//	Suspended = false로 실행가능상태로 만듦.
	Suspended		= false;                           //	스레드 중지할지 결정하는 property

}
//---------------------------------------------------------------------------
__fastcall TTcpThread::~TTcpThread()
{
	delete m_pAppInfo;
	delete IdUDPServerThr;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::Execute()
{
	MSG stMsg;                                           // 메인폼에서 보낸 메세지를 받을 그릇
	while(!Terminated){                                  //	Terminated는 속성으로서 현재 쓰레드가 작업중인지의 여부를 가리키는 boolean형 속성
		try{
			if(GetMessage(&stMsg, NULL, 0, 0) == 0){
				Terminate();                             //	메세지의 값이 0이면(메세지가 없으면)
			}else{
				switch(stMsg.message){
					case WM_TCP_OPEN: {                   //	메세지가 WM_TCP_OPEN이면
						fnTcpOpen();
						break;
					}
					case WM_TCP_SAVE06: {                   //	메세지가 WM_TCP_OPEN이면
						fnSaveData06();
						break;
					}
					case WM_TCP_SAVE07: {                   //	메세지가 WM_TCP_OPEN이면
						fnSaveData07();
						break;
					}
					case WM_SEND_TEST:
						fnSendTest();
						break;
				}
			}
		}
		catch(Exception& E){
			OutputDebugString(E.Message.c_str());
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnTcpOpen()
{
	IdUDPServerThr->DefaultPort = m_pAppInfo->Port;
	IdUDPServerThr->Active		= true;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::IdUDPServerThrUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
	int iResult = 0;
	TProtocol *pRecvPack;
	BYTE byBuf[MAX_TCP_BUFFER];
	ZeroMemory(byBuf, sizeof(byBuf));
	BytesToRaw(AData, byBuf, sizeof(byBuf));

	pRecvPack = new TProtocol();
	if((iResult=pRecvPack->fnDecoding(byBuf, AData.Length)) == 0){
		switch (pRecvPack->Code) {
			case 0x05 : fnRecvThrData05(pRecvPack); break;
			case 0x06 : fnSendData06(pRecvPack); break;
			case 0x07 : fnSendData07(pRecvPack); break;
			default	  : break;
		}
	}else{
		OutputDebugStringW(L"Decoding Error");
	}
	delete pRecvPack;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnRecvThrData05(TProtocol *a_pRecvPack)
{
	TTcpData05 *pData;
	pData = (TTcpData05*)a_pRecvPack->Body;
	switch (pData->CtrlCode) {
		case 0x30 : m_pAppInfo->Status->TcpData05->ModulPower	   = pData->CtrlData01; break;
		case 0x31 :	m_pAppInfo->Status->TcpData05->ResetTime	   = pData->CtrlData01; break;
		case 0x32 :	m_pAppInfo->Status->TcpData05->TryCount		   = pData->CtrlData01; break;
		case 0x33 :	m_pAppInfo->Status->TcpData05->ControlTime	   = pData->CtrlData14; break;
		case 0x34 :	m_pAppInfo->Status->TcpData05->RunTime		   = pData->CtrlData08; break;
		case 0x35 :	m_pAppInfo->Status->TcpData05->BlinkCycle	   = pData->CtrlData01; break;
		case 0x36 :	m_pAppInfo->Status->TcpData05->ScinarioRunTime = pData->CtrlData01; break;
		case 0x37 :	m_pAppInfo->Status->TcpData05->BrightControl1  = pData->CtrlData02; break;
		case 0x38 :	m_pAppInfo->Status->TcpData05->FanControl	   = pData->CtrlData01; break;
		case 0x39 :	m_pAppInfo->Status->TcpData05->HeaterControl   = pData->CtrlData01; break;
		case 0x40 :	m_pAppInfo->Status->TcpData05->LampControl	   = pData->CtrlData01; break;
		case 0x41 :	m_pAppInfo->Status->TcpData05->LedControl	   = pData->CtrlData01; break;
		default	  : break;
	}
	// Save To File
	fnSaveData05(pData);
	fnSendThrData(pData->CtrlCode);
	delete pData;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSaveData05(TTcpData05 *a_pRecvData)
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);
	switch (a_pRecvData->CtrlCode) {
		case 0x30 : pIni->WriteInteger("Data05", "ModulPower"	   , m_pAppInfo->Status->TcpData05->ModulPower	   );break;
		case 0x31 :	pIni->WriteInteger("Data05", "ResetTime"	   , m_pAppInfo->Status->TcpData05->ResetTime	   );break;
		case 0x32 :	pIni->WriteInteger("Data05", "TryCount"		   , m_pAppInfo->Status->TcpData05->TryCount	   );break;
		case 0x33 :	pIni->WriteString ("Data05", "ControlTime"	   , m_pAppInfo->Status->TcpData05->ControlTime	   );break;
		case 0x34 :	pIni->WriteString ("Data05", "RunTime"	 	   , m_pAppInfo->Status->TcpData05->RunTime		   );break;
		case 0x35 :	pIni->WriteInteger("Data05", "BlinkCycle"	   , m_pAppInfo->Status->TcpData05->BlinkCycle	   );break;
		case 0x36 :	pIni->WriteInteger("Data05", "ScinarioRunTime" , m_pAppInfo->Status->TcpData05->ScinarioRunTime);break;
		case 0x37 :	pIni->WriteInteger("Data05", "BrightControl"   , m_pAppInfo->Status->TcpData05->BrightControl1 );break;
		case 0x38 :	pIni->WriteInteger("Data05", "FanControl"	   , m_pAppInfo->Status->TcpData05->FanControl	   );break;
		case 0x39 :	pIni->WriteInteger("Data05", "HeaterControl"   , m_pAppInfo->Status->TcpData05->HeaterControl  );break;
		case 0x40 :	pIni->WriteInteger("Data05", "LampControl" 	   , m_pAppInfo->Status->TcpData05->LampControl	   );break;
		case 0x41 :	pIni->WriteInteger("Data05", "LedControl"	   , m_pAppInfo->Status->TcpData05->LedControl	   );break;
		default	  : break;
	}
	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSendThrData(int a_iCode)
{
	PostMessage(Application->MainFormHandle, WM_TCP_RECV05, (WPARAM)5, (LPARAM)a_iCode);
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSaveData06()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);

	pIni->WriteInteger("Data06", "Door"		  	        , m_pAppInfo->Status->TcpData06->Door 		         );
	pIni->WriteInteger("Data06", "Power"		        , m_pAppInfo->Status->TcpData06->Power 	             );
	pIni->WriteInteger("Data06", "Fan"			        , m_pAppInfo->Status->TcpData06->Fan 		         );
	pIni->WriteInteger("Data06", "Heater"		        , m_pAppInfo->Status->TcpData06->Heater 	         );
	pIni->WriteInteger("Data06", "OuterLight"	        , m_pAppInfo->Status->TcpData06->OuterLight          );
	pIni->WriteInteger("Data06", "FormKind"	  	        , m_pAppInfo->Status->TcpData06->FormKind 	         );
	pIni->WriteInteger("Data06", "ReplayCheck"	        , m_pAppInfo->Status->TcpData06->ReplayCheck         );
	pIni->WriteInteger("Data06", "PowerOdd"	  	        , m_pAppInfo->Status->TcpData06->PowerOdd 	         );
	pIni->WriteInteger("Data06", "ModulOdd"	  	        , m_pAppInfo->Status->TcpData06->ModulOdd 	         );
	pIni->WriteInteger("Data06", "Temperature"	        , m_pAppInfo->Status->TcpData06->Temperature         );
	pIni->WriteInteger("Data06", "DisplayBright"        , m_pAppInfo->Status->TcpData06->DisplayBright       );
	pIni->WriteInteger("Data06", "Etc2"		  	        , m_pAppInfo->Status->TcpData06->Etc2		         );

	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSaveData07()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);

	pIni->WriteInteger("Data07", "PowerMode" 		 	, m_pAppInfo->Status->TcpData07->PowerMode 			 );
	pIni->WriteInteger("Data07", "Fan"				 	, m_pAppInfo->Status->TcpData07->Fan				 );
	pIni->WriteInteger("Data07", "FanTemper"		 	, m_pAppInfo->Status->TcpData07->FanTemper			 );
	pIni->WriteInteger("Data07", "Heater"			 	, m_pAppInfo->Status->TcpData07->Heater				 );
	pIni->WriteInteger("Data07", "HeaterTemper"		 	, m_pAppInfo->Status->TcpData07->HeaterTemper		 );
	pIni->WriteInteger("Data07", "DisplayBright"	   	, m_pAppInfo->Status->TcpData07->DisplayBright	  	 );
	pIni->WriteInteger("Data07", "FlashCycle"		  	, m_pAppInfo->Status->TcpData07->FlashCycle			 );
	pIni->WriteInteger("Data07", "OuterLightOperating" 	, m_pAppInfo->Status->TcpData07->OuterLightOperating );
	pIni->WriteInteger("Data07", "OuterLightOnBright"  	, m_pAppInfo->Status->TcpData07->OuterLightOnBright	 );
	pIni->WriteInteger("Data07", "Scenario"			   	, m_pAppInfo->Status->TcpData07->Scenario			 );
	pIni->WriteInteger("Data07", "Etc1"				   	, m_pAppInfo->Status->TcpData07->Etc1				 );
	pIni->WriteInteger("Data07", "Etc2"				   	, m_pAppInfo->Status->TcpData07->Etc2				 );

	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSendData06(TProtocol *a_pRecvPack)
{
	TProtocol  *pSendPack = new TProtocol();
	TTcpData06 *pData 	  = new TTcpData06(m_pAppInfo->Status->TcpData06);		//	복사 생성자

	pSendPack->VMSID      = a_pRecvPack->VMSID;
	pSendPack->Code       = a_pRecvPack->Code;
	pSendPack->SFNo	      = a_pRecvPack->SFNo;
	pSendPack->AFNo       = a_pRecvPack->AFNo;
	pSendPack->Body       = (void*)pData;

	fnSendIOData(pSendPack);
	delete pSendPack;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSendData07(TProtocol *a_pRecvPack)
{
	TProtocol  *pSendPack = new TProtocol();
	TTcpData07 *pData 	  = new TTcpData07(m_pAppInfo->Status->TcpData07);

	pSendPack->VMSID      = a_pRecvPack->VMSID;
	pSendPack->Code       = a_pRecvPack->Code;
	pSendPack->SFNo	      = a_pRecvPack->SFNo;
	pSendPack->AFNo       = a_pRecvPack->AFNo;
	pSendPack->Body       = (void*)pData;

	fnSendIOData(pSendPack);
	delete pSendPack;              //	프로토콜 소멸할때 fnDeleteBody호출해서 바디메모리 delete
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSendIOData(TProtocol *a_pSendPack)
{
	int iResult = 0;
	if((iResult=a_pSendPack->fnEncoding()) == 0){
		IdUDPServerThr->SendBuffer(m_pAppInfo->Ip , m_pAppInfo->Port, RawToBytes(a_pSendPack->SendPacket, a_pSendPack->SendPacketSize));

		UnicodeString sTemp;
		UnicodeString sLog = "";
		for(int i=0; i<a_pSendPack->SendPacketSize; i++){
			sLog += sTemp.sprintf(L"%02X ", a_pSendPack->SendPacket[i]);
		}
		OutputDebugString(sLog.c_str());

	}else{
		//Log iResult;
		OutputDebugStringW(L"Encoding Error ");
	}
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::fnSendTest()
{
	int iResult = 0;
	TProtocol *pRecvPack;

	pRecvPack = new TProtocol();
	pRecvPack->VMSID = 0xFF;
	pRecvPack->Code  = 0x06;
	pRecvPack->SFNo  = 0x01;
	pRecvPack->AFNo  = 0x01;

	fnSendData06(pRecvPack);
	delete pRecvPack;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


