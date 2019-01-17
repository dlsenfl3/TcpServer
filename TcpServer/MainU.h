//---------------------------------------------------------------------------

#ifndef MainUH
#define MainUH
//---------------------------------------------------------------------------
#include "TcpCommU.h"
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxPC.hpp"
#include "dxBarBuiltInMenu.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinscxPCPainter.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "cxClasses.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "cxContainer.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxLayoutcxEditAdapters.hpp"
#include "dxLayoutLookAndFeels.hpp"
#include "cxDBEdit.hpp"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TMainF : public TForm
{
__published:	// IDE-managed Components
	TPanel *paForm;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TcxTabSheet *cxTabSheet1;
	TPanel *Panel2;
	TRadioGroup *rdBrightControl;
	TRadioGroup *rdFanControl;
	TRadioGroup *rdHeaterControl;
	TRadioGroup *rdLampControl;
	TRadioGroup *rdLedControl;
	TRadioGroup *rdModulPower;
	TPanel *Panel3;
	TLabel *lbResetTime;
	TLabel *lbTryCount;
	TLabel *lbControlTime;
	TLabel *lbRunTime;
	TLabel *lbBlinkCycle;
	TLabel *lbScinarioRunTime;
	TcxTextEdit *edResetTime;
	TcxTextEdit *edTryCount;
	TcxTextEdit *edControlTime;
	TcxTextEdit *edBlinkCycle;
	TcxTextEdit *edRunTime;
	TcxTextEdit *edScinarioRunTime;
	TRadioGroup *rdReStart;
	TRadioGroup *rdFanState;
	TRadioGroup *rdPowerError;
	TPanel *Panel4;
	TLabel *lbDisplayBright;
	TLabel *lbTemperature;
	TLabel *lbEtc;
	TRadioGroup *rdModulError;
	TRadioGroup *rdFormKind;
	TRadioGroup *rdOuterLampState;
	TRadioGroup *rdHeaterState;
	TRadioGroup *rdPowerState;
	TRadioGroup *rdDoor;
	TcxTextEdit *edTemperature;
	TcxTextEdit *edDisplayBright;
	TcxTextEdit *edEtc;
	TRadioGroup *rdOuterLampRun;
	TPanel *Panel5;
	TLabel *lbFanRunTemperature;
	TLabel *lbEtc1;
	TLabel *rdHeaterRunTemperature;
	TLabel *lbBlinkCircle;
	TLabel *lbLampRunBright;
	TLabel *lbScinarioTransTime;
	TRadioGroup *rdDisplayBright;
	TRadioGroup *rdPowerControlMode;
	TRadioGroup *rdFanRunMode;
	TRadioGroup *rdHeaterRunMode;
	TcxTextEdit *edFanRunTemperature;
	TcxTextEdit *edHeaterRunTemperature;
	TcxTextEdit *edLampRunBright;
	TcxTextEdit *edEtc1;
	TcxTextEdit *edBlinkCircle;
	TcxTextEdit *edScinarioTransTime;
	TLabel *lbEtc2;
	TcxTextEdit *edEtc2;
	TIdTCPServer *IdTCPServer1;
	TButton *btSave05;
	TButton *btSave06;
	TButton *btSave07;
	TButton *btSave;
	TMaskEdit *edMaskTest;
	void __fastcall btSaveClick(TObject *Sender);
private:
	TProtocol 	*m_pProtocol;
	TTcpData06 	*m_pData06;
public:		// User declarations
	__fastcall TMainF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainF *MainF;
//---------------------------------------------------------------------------
#endif
