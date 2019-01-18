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
#pragma resource "*.dfm"
TMainF *MainF;
//---------------------------------------------------------------------------
__fastcall TMainF::TMainF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TMainF::~TMainF()
{
}
//---------------------------------------------------------------------------
void __fastcall TMainF::btSaveClick(TObject *Sender)
{
	int iActivePage = cxPageControl1->ActivePageIndex;
	UnicodeString sTemp;
	m_pProtocol = new TProtocol();

	enum CTRL_PAGE{
		CtrlPage = 0,
		StatePage,
		LocalPage,
	};


	switch (iActivePage) {
		case StatePage : {
//			ShowMessage(StatePage);
			TTcpData06 *TcpData06 = new TTcpData06;
			sTemp = edMaskTemper->Text;
			TcpData06->Temperature 		= StrToInt(sTemp);//*(BYTE*)sTemp.c_str();
//			stData06.byDisplayBright 	= StrToInt(edMaskBright->Text);
//			stData06.byEtc2				= *(BYTE*)(edEtc->Text).c_str();
//			stData06.byFoamKind 		= rdFormKind->ItemIndex;
//			stData06.byPower 			= rdPowerState->ItemIndex;
//			stData06.byOuterLight 		= rdOuterLampState->ItemIndex;
//			stData06.byReplayCheck 		= rdReStart->ItemIndex;
//			stData06.byDoor 			= rdDoor->ItemIndex;
//			stData06.byFan 				= rdFanState->ItemIndex;
//			stData06.byHeater 			= rdHeaterState->ItemIndex;
//			stData06.byModulOdd 		= rdModulError->ItemIndex;
//			stData06.byPowerOdd 		= rdPowerError->ItemIndex;
//			m_pData06->Data 			= stData06;
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
void __fastcall TMainF::IdTCPServer1Execute(TIdContext *AContext)
{
//
}
//---------------------------------------------------------------------------

