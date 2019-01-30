//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainU.h"
//#include "stdio.h"
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
	m_pData05 = new TTcpData05();
	m_pData06 = new TTcpData06();
	m_pData07 = new TTcpData07();
}
//---------------------------------------------------------------------------
__fastcall TMainF::~TMainF()
{
	delete m_pData05;
	delete m_pData06;
	delete m_pData07;
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
		case StatePage : fnSaveData06(); break;
		case LocalPage : fnSaveData07(); break;
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveToMem()
{
	m_pData06->Door 		       	= rdDoor->ItemIndex			       	;
	m_pData06->Power 		       	= rdPowerState->ItemIndex	       	;
	m_pData06->Fan 			       	= rdFanState->ItemIndex		       	;
	m_pData06->Heater 		       	= rdHeaterState->ItemIndex	       	;
	m_pData06->OuterLight 	       	= rdOuterLampState->ItemIndex      	;
	m_pData06->FormKind 	       	= rdFormKind->ItemIndex		       	;
	m_pData06->ReplayCheck 	       	= rdReStart->ItemIndex		       	;
	m_pData06->PowerOdd 	       	= rdPowerError->ItemIndex	       	;
	m_pData06->ModulOdd 	       	= rdModulError->ItemIndex	       	;
	m_pData06->Temperature 	       	= StrToInt(edMaskTemper->Text)     	; //*(BYTE*)sTemp.c_str();
	m_pData06->DisplayBright       	= StrToInt(edMaskBright->Text)     	;
	m_pData06->Etc2			       	= StrToInt(edMaskEtc->Text)	       	; //*(BYTE*)(edEtc->Text).c_str();

	m_pData07->PowerMode 			= rdPowerControlMode->ItemIndex		;
	m_pData07->Fan					= rdFanRunMode->ItemIndex			;
	m_pData07->FanTemper			= StrToInt(edMaskFanTemp->Text)		;
	m_pData07->Heater				= rdHeaterRunMode->ItemIndex		;
	m_pData07->HeaterTemper			= StrToInt(edMaskHeaterTemp->Text)	;
	m_pData07->DisplayBright	    = rdDisplayBright->ItemIndex		;
	m_pData07->FlashCycle			= StrToInt(edMaskFlashCycle->Text)	;
	m_pData07->OuterLightOperating 	= rdOuterLampRun->ItemIndex			;
	m_pData07->OuterLightOnBright	= StrToInt(edMaskLamp->Text)		;
	m_pData07->Scenario			   	= StrToInt(edMaskScenario->Text)	;
	m_pData07->Etc1				   	= StrToInt(edMaskEtc1->Text)		;
	m_pData07->Etc2				   	= StrToInt(edMaskEtc2->Text)		;

}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnLoadData()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile* pIni  = new TIniFile(sPath);

	// App 섹션의 Ip주소와 Port번호 가져옴
	m_sIP 	= pIni->ReadString	("App", "IPAddress", "127.0.0.1");
	m_wPORT = pIni->ReadInteger	("App", "Port"	   ,  5000		);
//	Memo1->Lines->Add(m_sIP);
//	Memo1->Lines->Add(IntToStr(m_wPORT));

	// Data05 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdModulPower->ItemIndex         = pIni->ReadInteger("Data05", "ModulPower"	   	     , 0 );
	edResetTime->Text               = pIni->ReadInteger("Data05", "ResetTime"	   	     , 0 );
	edTryCount->Text                = pIni->ReadInteger("Data05", "TryCount"	         , 0 );
	edControlTime->Text             = pIni->ReadInteger("Data05", "ControlTime"	   	     , 0 );
	edRunTime->Text                 = pIni->ReadInteger("Data05", "RunTime"	 	   	     , 0 );
	edBlinkCycle->Text              = pIni->ReadInteger("Data05", "BlinkCycle"	   	     , 0 );
	edScinarioRunTime->Text         = pIni->ReadInteger("Data05", "ScinarioRunTime"      , 0 );
	rdBrightControl->ItemIndex      = pIni->ReadInteger("Data05", "BrightControl"        , 0 );
	rdFanControl->ItemIndex         = pIni->ReadInteger("Data05", "FanControl"	         , 0 );
	rdHeaterControl->ItemIndex      = pIni->ReadInteger("Data05", "HeaterControl"        , 0 );
	rdLampControl->ItemIndex        = pIni->ReadInteger("Data05", "LampControl"          , 0 );
	rdLedControl->ItemIndex         = pIni->ReadInteger("Data05", "LedControl"	         , 0 );

	// Data06 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdDoor->ItemIndex 			    = pIni->ReadInteger("Data06", "Door"		         , 0 );
	rdPowerState->ItemIndex 	    = pIni->ReadInteger("Data06", "Power"		         , 0 );
	rdFanState->ItemIndex 		    = pIni->ReadInteger("Data06", "Fan"			         , 0 );
	rdHeaterState->ItemIndex 	    = pIni->ReadInteger("Data06", "Heater"		         , 0 );
	rdOuterLampState->ItemIndex     = pIni->ReadInteger("Data06", "OuterLight"	         , 0 );
	rdFormKind->ItemIndex 		    = pIni->ReadInteger("Data06", "FormKind"	         , 0 );
	rdReStart->ItemIndex 		    = pIni->ReadInteger("Data06", "ReplayCheck"	         , 0 );
	rdPowerError->ItemIndex 	    = pIni->ReadInteger("Data06", "PowerOdd"	         , 0 );
	rdModulError->ItemIndex 	    = pIni->ReadInteger("Data06", "ModulOdd"	         , 0 );
	edMaskTemper->Text 			    = pIni->ReadInteger("Data06", "Temperature"	         , 0 );
	edMaskBright->Text 			    = pIni->ReadInteger("Data06", "DisplayBright" 	     , 0 );
	edMaskEtc->Text 			    = pIni->ReadInteger("Data06", "Etc2"		   	     , 0 );

	// Data07 섹션의 키이름과 키값을 가져옴 	ex) Door = 0
	rdPowerControlMode->ItemIndex   = pIni->ReadInteger("Data07", "PowerMode" 	   		 , 0 );
	rdFanRunMode->ItemIndex         = pIni->ReadInteger("Data07", "Fan"		  		 	 , 0 );
	edMaskFanTemp->Text    			= pIni->ReadInteger("Data07", "FanTemper"	  		 , 0 );
	rdHeaterRunMode->ItemIndex  	= pIni->ReadInteger("Data07", "Heater"		   	   	 , 0 );
	edMaskHeaterTemp->Text 			= pIni->ReadInteger("Data07", "HeaterTemper"		 , 0 );
	rdDisplayBright->ItemIndex  	= pIni->ReadInteger("Data07", "DisplayBright"	   	 , 0 );
	edMaskFlashCycle->Text 			= pIni->ReadInteger("Data07", "FlashCycle"			 , 0 );
	rdOuterLampRun->ItemIndex   	= pIni->ReadInteger("Data07", "OuterLightOperating"  , 0 );
	edMaskLamp->Text      			= pIni->ReadInteger("Data07", "OuterLightOnBright"	 , 0 );
	edMaskScenario->Text   			= pIni->ReadInteger("Data07", "Scenario"			 , 0 );
	edMaskEtc1->Text       			= pIni->ReadInteger("Data07", "Etc1"				 , 0 );
	edMaskEtc2->Text       			= pIni->ReadInteger("Data07", "Etc2"				 , 0 );

	delete pIni;
	//  메모리에 데이터를 넣기위해 호출
	fnSaveToMem();
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveData05()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);

	pIni->WriteInteger("Data05", "ModulPower"	   , rdModulPower->ItemIndex 	  		);
	pIni->WriteInteger("Data05", "ResetTime"	   , StrToInt(edResetTime->Text)  		);
	pIni->WriteInteger("Data05", "TryCount"		   , StrToInt(edTryCount->Text)   		);
	pIni->WriteInteger("Data05", "ControlTime"	   , StrToInt(edControlTime->Text)		);
	pIni->WriteInteger("Data05", "RunTime"	 	   , StrToInt(edRunTime->Text) 	  		);
	pIni->WriteInteger("Data05", "BlinkCycle"	   , StrToInt(edBlinkCycle->Text) 		);
	pIni->WriteInteger("Data05", "ScinarioRunTime" , StrToInt(edScinarioRunTime->Text)	);
	pIni->WriteInteger("Data05", "BrightControl"   , rdBrightControl->ItemIndex   	  	);
	pIni->WriteInteger("Data05", "FanControl"	   , rdFanControl->ItemIndex 	  		);
	pIni->WriteInteger("Data05", "HeaterControl"   , rdHeaterControl->ItemIndex   		);
	pIni->WriteInteger("Data05", "LampControl" 	   , rdLampControl->ItemIndex     		);
	pIni->WriteInteger("Data05", "LedControl"	   , rdLedControl->ItemIndex 	 		);

	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveData06()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);

	fnSaveToMem();

	pIni->WriteInteger("Data06", "Door"		  	 , m_pData06->Door 			);
	pIni->WriteInteger("Data06", "Power"		 , m_pData06->Power 	  	);
	pIni->WriteInteger("Data06", "Fan"			 , m_pData06->Fan 		   	);
	pIni->WriteInteger("Data06", "Heater"		 , m_pData06->Heater 	    );
	pIni->WriteInteger("Data06", "OuterLight"	 , m_pData06->OuterLight 	);
	pIni->WriteInteger("Data06", "FormKind"	  	 , m_pData06->FormKind 		);
	pIni->WriteInteger("Data06", "ReplayCheck"	 , m_pData06->ReplayCheck 	);
	pIni->WriteInteger("Data06", "PowerOdd"	  	 , m_pData06->PowerOdd 		);
	pIni->WriteInteger("Data06", "ModulOdd"	  	 , m_pData06->ModulOdd 		);
	pIni->WriteInteger("Data06", "Temperature"	 , m_pData06->Temperature 	);
	pIni->WriteInteger("Data06", "DisplayBright" , m_pData06->DisplayBright	);
	pIni->WriteInteger("Data06", "Etc2"		  	 , m_pData06->Etc2			);

	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSaveData07()
{
	AnsiString sPath;
	sPath 			= ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile *pIni  = new TIniFile(sPath);

	fnSaveToMem();

	pIni->WriteInteger("Data07", "PowerMode" 		 	, m_pData07->PowerMode 			 );
	pIni->WriteInteger("Data07", "Fan"				 	, m_pData07->Fan				 );
	pIni->WriteInteger("Data07", "FanTemper"		 	, m_pData07->FanTemper			 );
	pIni->WriteInteger("Data07", "Heater"			 	, m_pData07->Heater			 	 );
	pIni->WriteInteger("Data07", "HeaterTemper"		 	, m_pData07->HeaterTemper		 );
	pIni->WriteInteger("Data07", "DisplayBright"	   	, m_pData07->DisplayBright	   	 );
	pIni->WriteInteger("Data07", "FlashCycle"		  	, m_pData07->FlashCycle			 );
	pIni->WriteInteger("Data07", "OuterLightOperating" 	, m_pData07->OuterLightOperating );
	pIni->WriteInteger("Data07", "OuterLightOnBright"  	, m_pData07->OuterLightOnBright	 );
	pIni->WriteInteger("Data07", "Scenario"			   	, m_pData07->Scenario			 );
	pIni->WriteInteger("Data07", "Etc1"				   	, m_pData07->Etc1				 );
	pIni->WriteInteger("Data07", "Etc2"				   	, m_pData07->Etc2				 );

	delete pIni;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
	int iResult = 0;
	TProtocol *pRecvPack;
	BYTE byBuf[MAX_BUFFER];
	ZeroMemory(byBuf, sizeof(byBuf));
	BytesToRaw(AData, byBuf, sizeof(byBuf));
//	sizeof(AData);
//	sizeof(AData.Length);

	pRecvPack = new TProtocol();
	if((iResult=pRecvPack->fnDecoding(byBuf, AData.Length)) == 0){
		switch (pRecvPack->Code) {
			case 0x05 : fnRecvData05(pRecvPack); break;
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
void __fastcall TMainF::fnRecvData05(TProtocol *a_pRecvPack)
{
	TTcpData05 *pData;
	pData = (TTcpData05*)a_pRecvPack->Body;
	m_pData05 = pData;
	switch (pData->CtrlCode) {
		case 0x30 : rdModulPower->ItemIndex 	= pData->CtrlData01; break;
		case 0x31 :	edResetTime->Text 			= pData->CtrlData01; break;
		case 0x32 :	edTryCount->Text 			= pData->CtrlData01; break;
		case 0x33 :	edControlTime->Text 		= pData->CtrlData14; break;
		case 0x34 :	edRunTime->Text 			= pData->CtrlData08; break;
		case 0x35 :	edBlinkCycle->Text 			= pData->CtrlData01; break;
		case 0x36 :	edScinarioRunTime->Text 	= pData->CtrlData01; break;
		case 0x37 :	rdBrightControl->ItemIndex 	= pData->CtrlData02; break;
		case 0x38 :	rdFanControl->ItemIndex 	= pData->CtrlData01; break;
		case 0x39 :	rdHeaterControl->ItemIndex 	= pData->CtrlData01; break;
		case 0x40 :	rdLampControl->ItemIndex 	= pData->CtrlData01; break;
		case 0x41 :	rdLedControl->ItemIndex 	= pData->CtrlData01; break;
		default	  : break;
	}
	// Save To File
	fnSaveData05();
	delete pData;
}


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
void __fastcall TMainF::FormShow(TObject *Sender)
{
	// Load From File
	fnLoadData();
	IdUDPServer1->Active = true;
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

