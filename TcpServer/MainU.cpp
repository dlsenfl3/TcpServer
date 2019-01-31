//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
#pragma link "cxTextEdit"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinscxPCPainter"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma resource "*.dfm"
TMainF *MainF;
//---------------------------------------------------------------------------
__fastcall TMainF::TMainF(TComponent* Owner)
	: TForm(Owner)
{
	m_pAppInfo = new TApplicationInfo();
//	m_pData05 = new TTcpData05();
//	m_pData06 = new TTcpData06();
//	m_pData07 = new TTcpData07();
}
//---------------------------------------------------------------------------
__fastcall TMainF::~TMainF()
{
	delete m_pAppInfo;

//	delete m_pData05;
//	delete m_pData06;
//	delete m_pData07;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::btSaveClick(TObject *Sender)
{
	int iActivePage = cxPageControl1->ActivePageIndex;
	UnicodeString sTemp = "";
	UnicodeString sUtem = "";

	enum CTRL_PAGE{
		CtrlPage = 0,
		StatePage,
		LocalPage,
	};
	switch (iActivePage) {
//		case CtrlPage  : fnSaveData05(); break;
		case StatePage : {
			fnSaveToMem06();
			PostThreadMessage(m_pAppInfo->ThreadId, WM_TCP_SAVE06, 0, 0);
			break;
		}
		case LocalPage : {
			fnSaveToMem07();
			PostThreadMessage(m_pAppInfo->ThreadId, WM_TCP_SAVE07, 0, 0);
			break;
		}
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveToMem05()
{
	//	05메모리
	m_pAppInfo->Status->TcpData05->ModulPower	        =  rdModulPower->ItemIndex 	  	    ;
	m_pAppInfo->Status->TcpData05->ResetTime	        =  StrToInt(edResetTime->Text)  	;
	m_pAppInfo->Status->TcpData05->TryCount		        =  StrToInt(edTryCount->Text)   	;
	m_pAppInfo->Status->TcpData05->ControlTime	        =  StrToInt(edControlTime->Text)	;
	m_pAppInfo->Status->TcpData05->RunTime		        =  StrToInt(edRunTime->Text) 	  	;
	m_pAppInfo->Status->TcpData05->BlinkCycle	        =  StrToInt(edBlinkCycle->Text) 	;
	m_pAppInfo->Status->TcpData05->ScinarioRunTime      =  StrToInt(edScinarioRunTime->Text);
	m_pAppInfo->Status->TcpData05->BrightControl1       =  rdBrightControl->ItemIndex   	;
	m_pAppInfo->Status->TcpData05->FanControl	        =  rdFanControl->ItemIndex 	  	    ;
	m_pAppInfo->Status->TcpData05->HeaterControl        =  rdHeaterControl->ItemIndex   	;
	m_pAppInfo->Status->TcpData05->LampControl	        =  rdLampControl->ItemIndex     	;
	m_pAppInfo->Status->TcpData05->LedControl	        =  rdLedControl->ItemIndex 	 	    ;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveToMem06()
{		//	06메모리
	m_pAppInfo->Status->TcpData06->Door 		        = rdDoor->ItemIndex			       	;
	m_pAppInfo->Status->TcpData06->Power 		        = rdPowerState->ItemIndex	       	;
	m_pAppInfo->Status->TcpData06->Fan 			        = rdFanState->ItemIndex		       	;
	m_pAppInfo->Status->TcpData06->Heater 		        = rdHeaterState->ItemIndex	       	;
	m_pAppInfo->Status->TcpData06->OuterLight 	        = rdOuterLampState->ItemIndex      	;
	m_pAppInfo->Status->TcpData06->FormKind 	        = rdFormKind->ItemIndex		       	;
	m_pAppInfo->Status->TcpData06->ReplayCheck 	        = rdReStart->ItemIndex		       	;
	m_pAppInfo->Status->TcpData06->PowerOdd 	        = rdPowerError->ItemIndex	       	;
	m_pAppInfo->Status->TcpData06->ModulOdd 	        = rdModulError->ItemIndex	       	;
	m_pAppInfo->Status->TcpData06->Temperature 	        = StrToInt(edMaskTemper->Text)     	; //*(BYTE*)sTemp.c_str();
	m_pAppInfo->Status->TcpData06->DisplayBright        = StrToInt(edMaskBright->Text)     	;
	m_pAppInfo->Status->TcpData06->Etc2			        = StrToInt(edMaskEtc->Text)	       	; //*(BYTE*)(edEtc->Text).c_str();
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveToMem07()
{		//	07메모리
	m_pAppInfo->Status->TcpData07->PowerMode 			= rdPowerControlMode->ItemIndex		;
	m_pAppInfo->Status->TcpData07->Fan					= rdFanRunMode->ItemIndex			;
	m_pAppInfo->Status->TcpData07->FanTemper			= StrToInt(edMaskFanTemp->Text)		;
	m_pAppInfo->Status->TcpData07->Heater				= rdHeaterRunMode->ItemIndex		;
	m_pAppInfo->Status->TcpData07->HeaterTemper			= StrToInt(edMaskHeaterTemp->Text)	;
	m_pAppInfo->Status->TcpData07->DisplayBright	    = rdDisplayBright->ItemIndex		;
	m_pAppInfo->Status->TcpData07->FlashCycle			= StrToInt(edMaskFlashCycle->Text)	;
	m_pAppInfo->Status->TcpData07->OuterLightOperating 	= rdOuterLampRun->ItemIndex			;
	m_pAppInfo->Status->TcpData07->OuterLightOnBright	= StrToInt(edMaskLamp->Text)		;
	m_pAppInfo->Status->TcpData07->Scenario			   	= StrToInt(edMaskScenario->Text)	;
	m_pAppInfo->Status->TcpData07->Etc1				   	= StrToInt(edMaskEtc1->Text)		;
	m_pAppInfo->Status->TcpData07->Etc2				   	= StrToInt(edMaskEtc2->Text)		;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnLoadData05(TMessage a_Msg)
{
	switch (a_Msg.LParam) {
		case 0x30 : rdModulPower->ItemIndex     = m_pAppInfo->Status->TcpData05->ModulPower		 ; break;
		case 0x31 :	edResetTime->Text           = m_pAppInfo->Status->TcpData05->ResetTime		 ; break;
		case 0x32 :	edTryCount->Text            = m_pAppInfo->Status->TcpData05->TryCount		 ; break;
		case 0x33 :	edControlTime->Text         = m_pAppInfo->Status->TcpData05->ControlTime	 ; break;
		case 0x34 :	edRunTime->Text             = m_pAppInfo->Status->TcpData05->RunTime		 ; break;
		case 0x35 :	edBlinkCycle->Text          = m_pAppInfo->Status->TcpData05->BlinkCycle		 ; break;
		case 0x36 :	edScinarioRunTime->Text     = m_pAppInfo->Status->TcpData05->ScinarioRunTime ; break;
		case 0x37 :	rdBrightControl->ItemIndex  = m_pAppInfo->Status->TcpData05->BrightControl1	 ; break;
		case 0x38 :	rdFanControl->ItemIndex     = m_pAppInfo->Status->TcpData05->FanControl		 ; break;
		case 0x39 :	rdHeaterControl->ItemIndex  = m_pAppInfo->Status->TcpData05->HeaterControl	 ; break;
		case 0x40 :	rdLampControl->ItemIndex    = m_pAppInfo->Status->TcpData05->LampControl	 ; break;
		case 0x41 :	rdLedControl->ItemIndex     = m_pAppInfo->Status->TcpData05->LedControl		 ; break;
		default	  : break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnLoadToForm()
{
	// App 섹션의 Ip주소와 Port번호 가져옴
//	m_sIP 	= m_pAppInfo->Ip;
//	m_wPORT = m_pAppInfo->Port;

	// Data05 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdModulPower->ItemIndex         = m_pAppInfo->Status->TcpData05->ModulPower		    ;
	edResetTime->Text               = m_pAppInfo->Status->TcpData05->ResetTime		    ;
	edTryCount->Text                = m_pAppInfo->Status->TcpData05->TryCount		    ;
	edControlTime->Text             = m_pAppInfo->Status->TcpData05->ControlTime	    ;
	edRunTime->Text                 = m_pAppInfo->Status->TcpData05->RunTime		    ;
	edBlinkCycle->Text              = m_pAppInfo->Status->TcpData05->BlinkCycle		    ;
	edScinarioRunTime->Text         = m_pAppInfo->Status->TcpData05->ScinarioRunTime    ;
	rdBrightControl->ItemIndex      = m_pAppInfo->Status->TcpData05->BrightControl1	    ;
	rdFanControl->ItemIndex         = m_pAppInfo->Status->TcpData05->FanControl		    ;
	rdHeaterControl->ItemIndex      = m_pAppInfo->Status->TcpData05->HeaterControl	    ;
	rdLampControl->ItemIndex        = m_pAppInfo->Status->TcpData05->LampControl	    ;
	rdLedControl->ItemIndex         = m_pAppInfo->Status->TcpData05->LedControl		    ;

	// Data06 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdDoor->ItemIndex 			    = m_pAppInfo->Status->TcpData06->Door 			    ;
	rdPowerState->ItemIndex 	    = m_pAppInfo->Status->TcpData06->Power 			    ;
	rdFanState->ItemIndex 		    = m_pAppInfo->Status->TcpData06->Fan 			    ;
	rdHeaterState->ItemIndex 	    = m_pAppInfo->Status->TcpData06->Heater 		    ;
	rdOuterLampState->ItemIndex     = m_pAppInfo->Status->TcpData06->OuterLight 	    ;
	rdFormKind->ItemIndex 		    = m_pAppInfo->Status->TcpData06->FormKind 		    ;
	rdReStart->ItemIndex 		    = m_pAppInfo->Status->TcpData06->ReplayCheck 	    ;
	rdPowerError->ItemIndex 	    = m_pAppInfo->Status->TcpData06->PowerOdd 		    ;
	rdModulError->ItemIndex 	    = m_pAppInfo->Status->TcpData06->ModulOdd 		    ;
	edMaskTemper->Text 			    = m_pAppInfo->Status->TcpData06->Temperature 	    ;
	edMaskBright->Text 			    = m_pAppInfo->Status->TcpData06->DisplayBright	    ;
	edMaskEtc->Text 			    = m_pAppInfo->Status->TcpData06->Etc2			    ;

	// Data07 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdPowerControlMode->ItemIndex   = m_pAppInfo->Status->TcpData07->PowerMode 			;
	rdFanRunMode->ItemIndex         = m_pAppInfo->Status->TcpData07->Fan				;
	edMaskFanTemp->Text    			= m_pAppInfo->Status->TcpData07->FanTemper			;
	rdHeaterRunMode->ItemIndex  	= m_pAppInfo->Status->TcpData07->Heater				;
	edMaskHeaterTemp->Text 			= m_pAppInfo->Status->TcpData07->HeaterTemper		;
	rdDisplayBright->ItemIndex  	= m_pAppInfo->Status->TcpData07->DisplayBright	  	;
	edMaskFlashCycle->Text 			= m_pAppInfo->Status->TcpData07->FlashCycle			;
	rdOuterLampRun->ItemIndex   	= m_pAppInfo->Status->TcpData07->OuterLightOperating;
	edMaskLamp->Text      			= m_pAppInfo->Status->TcpData07->OuterLightOnBright	;
	edMaskScenario->Text   			= m_pAppInfo->Status->TcpData07->Scenario			;
	edMaskEtc1->Text       			= m_pAppInfo->Status->TcpData07->Etc1				;
	edMaskEtc2->Text       			= m_pAppInfo->Status->TcpData07->Etc2				;

}
//---------------------------------------------------------------------------
//void __fastcall TMainF::fnSaveData05()
//{
//	AnsiString sPath;
//	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
//	TIniFile *pIni  = new TIniFile(sPath);
//
////	fnSaveToMem();
//
//	pIni->WriteInteger("Data05", "ModulPower"	        , m_pAppInfo->Status->TcpData05->ModulPower		     );
//	pIni->WriteInteger("Data05", "ResetTime"	        , m_pAppInfo->Status->TcpData05->ResetTime		     );
//	pIni->WriteInteger("Data05", "TryCount"		        , m_pAppInfo->Status->TcpData05->TryCount		     );
//	pIni->WriteString ("Data05", "ControlTime"	        , m_pAppInfo->Status->TcpData05->ControlTime	     );
//	pIni->WriteString ("Data05", "RunTime"	 	        , m_pAppInfo->Status->TcpData05->RunTime		     );
//	pIni->WriteInteger("Data05", "BlinkCycle"	        , m_pAppInfo->Status->TcpData05->BlinkCycle		     );
//	pIni->WriteInteger("Data05", "ScinarioRunTime"      , m_pAppInfo->Status->TcpData05->ScinarioRunTime     );
//	pIni->WriteInteger("Data05", "BrightControl"        , m_pAppInfo->Status->TcpData05->BrightControl1	     );
//	pIni->WriteInteger("Data05", "FanControl"	        , m_pAppInfo->Status->TcpData05->FanControl		     );
//	pIni->WriteInteger("Data05", "HeaterControl"        , m_pAppInfo->Status->TcpData05->HeaterControl	     );
//	pIni->WriteInteger("Data05", "LampControl" 	        , m_pAppInfo->Status->TcpData05->LampControl	     );
//	pIni->WriteInteger("Data05", "LedControl"	        , m_pAppInfo->Status->TcpData05->LedControl		     );
//
//	delete pIni;
//}
//---------------------------------------------------------------------------
//void __fastcall TMainF::fnSaveData06()
//{
//	AnsiString sPath;
//	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
//	TIniFile *pIni  = new TIniFile(sPath);
//
//	fnSaveToMem06();
//
//	pIni->WriteInteger("Data06", "Door"		  	        , m_pAppInfo->Status->TcpData06->Door 		         );
//	pIni->WriteInteger("Data06", "Power"		        , m_pAppInfo->Status->TcpData06->Power 	             );
//	pIni->WriteInteger("Data06", "Fan"			        , m_pAppInfo->Status->TcpData06->Fan 		         );
//	pIni->WriteInteger("Data06", "Heater"		        , m_pAppInfo->Status->TcpData06->Heater 	         );
//	pIni->WriteInteger("Data06", "OuterLight"	        , m_pAppInfo->Status->TcpData06->OuterLight          );
//	pIni->WriteInteger("Data06", "FormKind"	  	        , m_pAppInfo->Status->TcpData06->FormKind 	         );
//	pIni->WriteInteger("Data06", "ReplayCheck"	        , m_pAppInfo->Status->TcpData06->ReplayCheck         );
//	pIni->WriteInteger("Data06", "PowerOdd"	  	        , m_pAppInfo->Status->TcpData06->PowerOdd 	         );
//	pIni->WriteInteger("Data06", "ModulOdd"	  	        , m_pAppInfo->Status->TcpData06->ModulOdd 	         );
//	pIni->WriteInteger("Data06", "Temperature"	        , m_pAppInfo->Status->TcpData06->Temperature         );
//	pIni->WriteInteger("Data06", "DisplayBright"        , m_pAppInfo->Status->TcpData06->DisplayBright       );
//	pIni->WriteInteger("Data06", "Etc2"		  	        , m_pAppInfo->Status->TcpData06->Etc2		         );
//
//	delete pIni;
//}////---------------------------------------------------------------------------
//void __fastcall TMainF::fnSaveData07()
//{
//	AnsiString sPath;
//	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
//	TIniFile *pIni  = new TIniFile(sPath);
//
//	fnSaveToMem07();
//
//	pIni->WriteInteger("Data07", "PowerMode" 		 	, m_pAppInfo->Status->TcpData07->PowerMode 			 );
//	pIni->WriteInteger("Data07", "Fan"				 	, m_pAppInfo->Status->TcpData07->Fan				 );
//	pIni->WriteInteger("Data07", "FanTemper"		 	, m_pAppInfo->Status->TcpData07->FanTemper			 );
//	pIni->WriteInteger("Data07", "Heater"			 	, m_pAppInfo->Status->TcpData07->Heater				 );
//	pIni->WriteInteger("Data07", "HeaterTemper"		 	, m_pAppInfo->Status->TcpData07->HeaterTemper		 );
//	pIni->WriteInteger("Data07", "DisplayBright"	   	, m_pAppInfo->Status->TcpData07->DisplayBright	  	 );
//	pIni->WriteInteger("Data07", "FlashCycle"		  	, m_pAppInfo->Status->TcpData07->FlashCycle			 );
//	pIni->WriteInteger("Data07", "OuterLightOperating" 	, m_pAppInfo->Status->TcpData07->OuterLightOperating );
//	pIni->WriteInteger("Data07", "OuterLightOnBright"  	, m_pAppInfo->Status->TcpData07->OuterLightOnBright	 );
//	pIni->WriteInteger("Data07", "Scenario"			   	, m_pAppInfo->Status->TcpData07->Scenario			 );
//	pIni->WriteInteger("Data07", "Etc1"				   	, m_pAppInfo->Status->TcpData07->Etc1				 );
//	pIni->WriteInteger("Data07", "Etc2"				   	, m_pAppInfo->Status->TcpData07->Etc2				 );
//
//	delete pIni;
//}
//---------------------------------------------------------------------------
//void __fastcall TMainF::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
//		  TIdSocketHandle *ABinding)
//{//
//	int iResult = 0;
//	TProtocol *pRecvPack;
//	BYTE byBuf[MAX_BUFFER];
//	ZeroMemory(byBuf, sizeof(byBuf));
//	BytesToRaw(AData, byBuf, sizeof(byBuf));
//
//	pRecvPack = new TProtocol();
//	if((iResult=pRecvPack->fnDecoding(byBuf, AData.Length)) == 0){
//		switch (pRecvPack->Code) {
//			case 0x05 : fnRecvData05(pRecvPack); break;
//			case 0x06 : fnSendData06(pRecvPack); break;
//			case 0x07 : fnSendData07(pRecvPack); break;
//			default	  : break;
//		}
//	}else{
//		OutputDebugStringW(L"Decoding Error");
//	}
//	delete pRecvPack;
//}
//---------------------------------------------------------------------------
//void __fastcall TMainF::fnRecvData05(TProtocol *a_pRecvPack)
//{
//	TTcpData05 *pData;
//	pData = (TTcpData05*)a_pRecvPack->Body;
//	switch (pData->CtrlCode) {
//		case 0x30 : rdModulPower->ItemIndex 	= pData->CtrlData01; break;
//		case 0x31 :	edResetTime->Text 			= pData->CtrlData01; break;
//		case 0x32 :	edTryCount->Text 			= pData->CtrlData01; break;
//		case 0x33 :	edControlTime->Text 		= pData->CtrlData14; break;
//		case 0x34 :	edRunTime->Text 			= pData->CtrlData08; break;
//		case 0x35 :	edBlinkCycle->Text 			= pData->CtrlData01; break;
//		case 0x36 :	edScinarioRunTime->Text 	= pData->CtrlData01; break;
//		case 0x37 :	rdBrightControl->ItemIndex 	= pData->CtrlData02; break;
//		case 0x38 :	rdFanControl->ItemIndex 	= pData->CtrlData01; break;
//		case 0x39 :	rdHeaterControl->ItemIndex 	= pData->CtrlData01; break;
//		case 0x40 :	rdLampControl->ItemIndex 	= pData->CtrlData01; break;
//		case 0x41 :	rdLedControl->ItemIndex 	= pData->CtrlData01; break;
//		default	  : break;
//	}
//	// Save To File
//	fnSaveData05();
//	delete pData;
//}

//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendData06(TProtocol *a_pRecvPack)
{
	TTcpData06 *pData;
	TProtocol  *pSendPack;
	pSendPack = new TProtocol();

	pSendPack->VMSID   = a_pRecvPack->VMSID;
	pSendPack->Code    = a_pRecvPack->Code;
	pSendPack->SFNo	   = a_pRecvPack->SFNo;
	pSendPack->AFNo    = a_pRecvPack->AFNo;

	pData = new TTcpData06(m_pData06);

	pSendPack->Body      = pData;
	fnSendIOData(pSendPack);
	delete pSendPack;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendData07(TProtocol *a_pRecvPack)
{
	TTcpData07 *pData;
	TProtocol  *pSendPack;
	pSendPack = new TProtocol();

	pSendPack->VMSID   = a_pRecvPack->VMSID;
	pSendPack->Code    = a_pRecvPack->Code;
	pSendPack->SFNo	   = a_pRecvPack->SFNo;
	pSendPack->AFNo    = a_pRecvPack->AFNo;

	pData = new TTcpData07(m_pData07);

	pSendPack->Body = (void*)pData;
	fnSendIOData(pSendPack);
	delete pSendPack;              //	프로토콜 소멸할때 fnDeleteBody호출해서 바디메모리 delete
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendIOData(TProtocol *a_pSendPack)
{
	int iResult = 0;
	if((iResult=a_pSendPack->fnEncoding()) == 0){
		IdUDPServer1->SendBuffer(m_sIP, m_wPORT, RawToBytes(a_pSendPack->SendPacket, a_pSendPack->SendPacketSize));

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
void __fastcall TMainF::Button1Click(TObject *Sender)
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
void __fastcall TMainF::Button2Click(TObject *Sender)
{
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::Timer1Timer(TObject *Sender)
{
	Button1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TMainF::Button3Click(TObject *Sender)
{
//	m_pData05->ControlTime = "19900205094535";
//	m_pData05->ControlTime = '12';

//	Edit1->Text = m_pData05->ControlTime;
//	Edit1->Text = sizeof(UnicodeString);
}
//---------------------------------------------------------------------------
void __fastcall TMainF::FormCreate(TObject *Sender)
{
	TTcpThread *pTcpThread;
	pTcpThread = new TTcpThread(m_pAppInfo);
	m_pAppInfo->ThreadId = pTcpThread->ThreadID;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::FormShow(TObject *Sender)
{
	// Load From File
	fnLoadToForm();
//	m_pThread->Start();                      //	스레드생성자에서  Suspended를 true로하면 정상실행가능
//	IdUDPServer1->Active = true;
	PostThreadMessage(m_pAppInfo->ThreadId, WM_TCP_OPEN, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainF::FormClose(TObject *Sender, TCloseAction &Action)
{
//	m_pThread->Terminate();
//	delete m_pThread;                    //	?????????????????????????????????????????????????????????????????????????????????
}
//---------------------------------------------------------------------------

void __fastcall TMainF::FormCloseQuery(TObject *Sender, bool &CanClose)
{

	CanClose = false;

		if(Application->MessageBox(L"프로그램을 종료하시겠습니까?", L"확인",
								   MB_YESNO|MB_ICONQUESTION|MB_APPLMODAL) == IDNO) return;



		if(m_pAppInfo->ThreadId){
			PostThreadMessage(m_pAppInfo->ThreadId, WM_QUIT, 0, 0);
		}

		CanClose = true;

}
//---------------------------------------------------------------------------

