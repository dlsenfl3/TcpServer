//---------------------------------------------------------------------------

#ifndef TcpCommUH
#define TcpCommUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>			//추가한 헤더
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
const int MAX_BUFFER_SIZE = 1024;
//---------------------------------------------------------------------------
class TTcpBase
{
private:
protected:
	int __fastcall fnDefaultEncoding(BYTE *pBuffer, int &iIndex, void *pData, int iDataSize);
	int __fastcall fnDefaultDecoding(BYTE *pBuffer, int &iIndex, int iSize, void *pData, int iDataSize);
public:
	__fastcall 	TTcpBase();
	__fastcall ~TTcpBase();

};
//---------------------------------------------------------------------------
struct TstHeader	//9바이트
{
	BYTE bySTX1;
	BYTE bySTX2;
	WORD wVMSID;
	BYTE byOpCode;
	BYTE bySFNo;
	BYTE byAFNo;
	WORD wDataLen;
};
//---------------------------------------------------------------------------
struct TstTail		//4바이트
{
	WORD wCRC_16;
	BYTE byETX1;
	BYTE byETX2;
};
//---------------------------------------------------------------------------
class TProtocol	: public TTcpBase
{
private:
	TstHeader m_stHeader;
	TstTail	  m_stTail;
	void	 *m_pBody;
public:
	__fastcall  TProtocol();
	__fastcall ~TProtocol();
public:
	int __fastcall fnEncoding();
	int __fastcall fnDecoding(BYTE *a_pBuffer, int a_iSize);
//	void __fastcall fnSetOpCode(int a_op);
};
//---------------------------------------------------------------------------
struct TstCode05
{
	BYTE byCtrlCode;
	BYTE byCtrlData01;
	BYTE byCtrlData02[2];
	char byCtrlData08[8];
	char byCtrlData14[14];
};
//---------------------------------------------------------------------------
class TTcpData05   	: public TTcpBase
{
private:
	TstCode05 m_stData;
public:
	__fastcall  TTcpData05();
	__fastcall ~TTcpData05();
};
//---------------------------------------------------------------------------
struct TstCode06							// State     //12바이트
{
	BYTE byDoor;							//	Open: 0x00, Close: 0x01, Unkown: 0x09
	BYTE byPower;							//  On: 0x00, 	Off: 0x01
	BYTE byFan;								//  On: 0x00, 	Off: 0x01,   Unkown: 0x09
	BYTE byHeater;                         	//  On: 0x00, 	Off: 0x01,   Unkown: 0x09
	BYTE byOuterLight;                 	   	//  On: 0x00, 	Off: 0x01
	BYTE byFoamKind;						//  CFoam: 0x00, 	DFoam: 0x01
	BYTE byReplayCheck;                	    //  Normal: 0x00, 	RePlay: 0x01
	BYTE byPowerOdd;						//	Eorror: 0x00,	Normal:	0x01,	0x02: Unknown
	BYTE byModulOdd;						//  Eorror: 0x00,	Normal:	0x01,	0x02: Unknown
	BYTE byTemperature;						//  Range:0x00 ~ 0xfe(-127~127),	0xff: Unknown
	BYTE byDisplayBright;             	    //  백분율 표기
	BYTE byEtc2;							// 	기타2
};
//---------------------------------------------------------------------------
class TTcpData06	: public TTcpBase
{
private:
	TstCode06 m_stData;
public:
	__fastcall  TTcpData06();
	__fastcall ~TTcpData06();
};
//---------------------------------------------------------------------------
struct TstCode07                      		// LocalState
{
	BYTE byPowerMode;					   	//	Off: 0x00,  On: 0x01, Auto: 0x02
	BYTE byFan;								//  Off: 0x00, 	On: 0x01, Auto: 0x02,  Unkown: 0x09
	BYTE byFanTemper;						//	Range:0x00 ~ 0x3f
	BYTE byEtc1;							// 	기타1
	BYTE byHeater;                        	//  Off: 0x00, 	On: 0x01, Auto: 0x02,  Unkown: 0x09
	BYTE byHeaterTemper;                  	//	Range:0x00 ~ 0x3f
	BYTE byDisplayBright;                 	//  Manual: 0x00,	Auto: 0x01
	BYTE byFlashCycle;						//	Range: 0x00 ~ 0x1e(0.1 ~ 3.0)
	BYTE byOuterLightOperating;				//	Off: 0x00,	On: 0x01,	Auto: 0x02
	BYTE byOuterLightOnBright;            	//	백분율 표기
	BYTE byDefaultScenarioWait;           	//	Range: 0x00 ~ 0x1e(분)
	BYTE byEtc2;							// 	기타2

	BYTE byLocalTime[6];                    //	년월일시분초
};
//---------------------------------------------------------------------------
class TTcpData07	: public TTcpBase
{
private:
	TstCode07 m_stData;
public:
	__fastcall  TTcpData07();
	__fastcall ~TTcpData07();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
