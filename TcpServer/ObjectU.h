//---------------------------------------------------------------------------

#ifndef ObjectUH
#define ObjectUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>			//추가한 헤더
#include "TcpCommU.h"
//---------------------------------------------------------------------------
	void __fastcall fnRecvData05(TProtocol *a_pRecvPack);
	void __fastcall fnSendData06(TProtocol *a_pRecvPack);
	void __fastcall fnSendData07(TProtocol *a_pRecvPack);
	void __fastcall fnSendIOData(TProtocol *a_pSendPack);

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
