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
}
//---------------------------------------------------------------------------
__fastcall TMainF::~TMainF()
{
//	delete m_pThread;		// 스레드 소스파일에서 FreeOnTerminate = false로 지정후 메인함수 소멸자에서 호출하면 정상실행.
	delete m_pAppInfo;
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
void __fastcall TMainF::Button1Click(TObject *Sender)
{
	PostThreadMessageA(m_pAppInfo->ThreadId, WM_SEND_TEST, 0, 0);
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
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::FormCreate(TObject *Sender)
{
	TTcpThread *m_pThread;
	m_pThread = new TTcpThread(m_pAppInfo);
	m_pAppInfo->ThreadId = m_pThread->ThreadID;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::FormShow(TObject *Sender)
{
	// Load From File
	fnLoadToForm();
	PostThreadMessage(m_pAppInfo->ThreadId, WM_TCP_OPEN, 0, 0);
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

