//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxPC"
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
#pragma link "cxClasses"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "cxDBEdit"
#pragma link "cspin"
#pragma resource "*.dfm"
TMainF *MainF;
//---------------------------------------------------------------------------
__fastcall TMainF::TMainF(TComponent* Owner)
	: TForm(Owner)
{
	sIpPort = "127.0.0.1";
	m_pData06 = new TTcpData06();

	//file load;

}
//---------------------------------------------------------------------------
__fastcall TMainF::~TMainF()
{
	delete m_pData06;
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
		case StatePage : {
			m_pData06->Temperature 		= StrToInt(edMaskTemper->Text);//*(BYTE*)sTemp.c_str();
			m_pData06->DisplayBright 	= StrToInt(edMaskBright->Text);
			m_pData06->Etc2				= *(BYTE*)(edEtc->Text).c_str();
			m_pData06->FormKind 		= rdFormKind->ItemIndex;
			m_pData06->Power 			= rdPowerState->ItemIndex;
			m_pData06->OuterLight 		= rdOuterLampState->ItemIndex;
			m_pData06->ReplayCheck 		= rdReStart->ItemIndex;
			m_pData06->Door 			= rdDoor->ItemIndex;
			m_pData06->Fan 				= rdFanState->ItemIndex;
			m_pData06->Heater 			= rdHeaterState->ItemIndex;
			m_pData06->ModulOdd 		= rdModulError->ItemIndex;
			m_pData06->PowerOdd 		= rdPowerError->ItemIndex;

			//file save;
			break;
			}
		case LocalPage : {
			break;
			}
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainF::Button1Click(TObject *Sender)
{
//	UnicodeString sLog;
//	sLog.sprintf(L"====>>> %d", m_pData06->FoamKind);
//	OutputDebugString(sLog.c_str());

//	TTcpData06 *pData06;
//	pData06 	    = new TTcpData06();
//	pData06->Door  = m_pData06->Door;
//	pData06->Power = m_pData06->Power;



//	TProtocol 	*pProtocol;
//	pProtocol = new TProtocol();
//	pProtocol->Body = (void*)pData06;
}
//---------------------------------------------------------------------------


void __fastcall TMainF::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding)
{
	BYTE byBuf[MAX_BUFFER];
	ZeroMemory(byBuf, sizeof(byBuf));
	BytesToRaw(AData, byBuf, sizeof(byBuf));
	m_pProtocol = new TProtocol();
	m_pProtocol->fnDecoding(byBuf, sizeof(byBuf));



	switch (m_pProtocol->Code) {
		case 0x05 :
			break;
		case 0x06 :
			break;
		case 0x07 :
			break;
	default:
        ;
	}

}
//---------------------------------------------------------------------------

