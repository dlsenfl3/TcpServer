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
	sIP   = "127.0.0.1";
	wPORT = 5000;
	//file load;

	m_pData06 = new TTcpData06();

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
void __fastcall TMainF::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
	int iResult = 0;
	TProtocol *pPrtl;
	BYTE byBuf[MAX_BUFFER];
	ZeroMemory(byBuf, sizeof(byBuf));
	BytesToRaw(AData, byBuf, sizeof(byBuf));

	pPrtl = new TProtocol();
	if((iResult=pPrtl->fnDecoding(byBuf, sizeof(byBuf))) == 0){
        switch (pPrtl->Code) {
			case 0x05 :
				break;
			case 0x06 :
				fnSendData06(pPrtl);
//				m_pProtocol->Body = m_pData06;
//				m_pProtocol->fnEncoding();
				break;
			case 0x07 :
				break;
			default:
				break;
		}
	}
	delete pPrtl;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendData06(TProtocol 	*a_pPrtl)              //	????????????
{
	TProtocol  *pPrtl;
	TTcpData06 *pData;

	pPrtl = new TProtocol();
	//보낼 프래임    //받은 프램임
	pPrtl->VMSID   = a_pPrtl->VMSID;
	pPrtl->Code    = a_pPrtl->Code;
	pPrtl->SFNo	   = a_pPrtl->SFNo;
	pPrtl->AFNo    = a_pPrtl->AFNo;

//	pData = new TTcpData06();
	pPrtl->Body = m_pData06;

	fnSendIOData(pPrtl);
	delete pPrtl;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendIOData(TProtocol 	*a_pPrtl)
{
	int iResult = 0;
	if((iResult=a_pPrtl->fnEncoding()) == 0){
		IdUDPServer1->SendBuffer(sIP, wPORT, RawToBytes(a_pPrtl->SendPacket, sizeof(a_pPrtl->SendPacket)));
	}else{
		//Log iResult;
	}
//	delete a_pPrtl;
}

