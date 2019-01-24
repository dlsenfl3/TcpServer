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

//	ShowMessage(edMaskTemper->Text);
//	ShowMessage(edMaskBright->Text);
//	ShowMessage(edMaskEtc->Text);

	switch (iActivePage) {
		case StatePage : {
			m_pData06->Temperature 		= StrToInt(edMaskTemper->Text);//*(BYTE*)sTemp.c_str();
			m_pData06->DisplayBright 	= StrToInt(edMaskBright->Text);
			m_pData06->Etc2				= StrToInt(edMaskEtc->Text);//*(BYTE*)(edEtc->Text).c_str();
			m_pData06->FormKind 		= rdFormKind->ItemIndex;
			m_pData06->Power 			= rdPowerState->ItemIndex;
			m_pData06->OuterLight 		= rdOuterLampState->ItemIndex;
			m_pData06->ReplayCheck 		= rdReStart->ItemIndex;
			m_pData06->Door 			= rdDoor->ItemIndex;
			m_pData06->Fan 				= rdFanState->ItemIndex;
			m_pData06->Heater 			= rdHeaterState->ItemIndex;
			m_pData06->ModulOdd 		= rdModulError->ItemIndex;
			m_pData06->PowerOdd 		= rdPowerError->ItemIndex;
			break;
			}
		case LocalPage : {
			m_pData07->FanTemper			= StrToInt(edMaskFanTemp->Text);
			m_pData07->HeaterTemper			= StrToInt(edMaskHeaterTemp->Text);
			m_pData07->Scenario				= StrToInt(edMaskScenario->Text);
			m_pData07->FlashCycle			= StrToInt(edMaskFlashCycle->Text);
			m_pData07->OuterLightOnBright	= StrToInt(edMaskLamp->Text);
			m_pData07->Etc1				   	= StrToInt(edMaskEtc1->Text);
			m_pData07->Etc2					= StrToInt(edMaskEtc2->Text);
			m_pData07->DisplayBright		= rdDisplayBright->ItemIndex;
			m_pData07->OuterLightOperating	= rdOuterLampRun->ItemIndex;
			m_pData07->PowerMode			= rdPowerControlMode->ItemIndex;
			m_pData07->Fan					= rdFanRunMode->ItemIndex;
			m_pData07->Heater				= rdHeaterRunMode->ItemIndex;
			break;
			}
		default:
			break;
	}
			//file save;
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

	pRecvPack = new TProtocol();
	if((iResult=pRecvPack->fnDecoding(byBuf, sizeof(byBuf))) == 0){
		switch (pRecvPack->Code) {
			case 0x05 : fnRecvData05(pRecvPack); break;
			case 0x06 : fnSendData06(pRecvPack); break;
			case 0x07 : fnSendData07(pRecvPack); break;
			default	  : break;
		}
	}else{
		ShowMessage("Decoding Error");
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

//	pData->Door   		 = m_pData06->Door;
//	pData->Power  		 = m_pData06->Power;
//	pData->Fan	  		 = m_pData06->Fan;
//	pData->Heater 		 = m_pData06->Heater;
//	pData->OuterLight 	 = m_pData06->OuterLight;
//	pData->FormKind	  	 = m_pData06->FormKind;
//	pData->ReplayCheck 	 = m_pData06->ReplayCheck;
//	pData->PowerOdd	   	 = m_pData06->PowerOdd;
//	pData->ModulOdd    	 = m_pData06->ModulOdd;
//	pData->Temperature 	 = m_pData06->Temperature;
//	pData->DisplayBright = m_pData06->DisplayBright;
//	pData->Etc2 		 = m_pData06->Etc2;

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
	delete pSendPack;
}
//---------------------------------------------------------------------------
void __fastcall TMainF::fnSendIOData(TProtocol *a_pSendPack)
{
	int iResult = 0;
	if((iResult=a_pSendPack->fnEncoding()) == 0){
//		IdUDPServer1->SendBuffer(sIP, wPORT, RawToBytes(a_pSendPack->SendPacket, a_pSendPack->SendPacketSize));

		UnicodeString sTemp;
		UnicodeString sLog = "";
		for(int i=0; i<a_pSendPack->SendPacketSize; i++){
			sLog += sTemp.sprintf(L"%02X ", a_pSendPack->SendPacket[i]);
		}
		OutputDebugString(sLog.c_str());

	}else{
		//Log iResult;
		ShowMessage("Encoding Error");
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainF::Button1Click(TObject *Sender)
{
	int iResult = 0;
	TProtocol *pRecvPack;
//	BYTE byBuf[MAX_BUFFER];
//	ZeroMemory(byBuf, sizeof(byBuf));
//	BytesToRaw(AData, byBuf, sizeof(byBuf));

	pRecvPack = new TProtocol();
	pRecvPack->VMSID = 0xFF;
	pRecvPack->Code  = 0x06;
	pRecvPack->SFNo  = 0x01;
	pRecvPack->AFNo  = 0x01;

	fnSendData06(pRecvPack);
	delete pRecvPack;
}
//---------------------------------------------------------------------------

