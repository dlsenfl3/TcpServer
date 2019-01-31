//---------------------------------------------------------------------------

#ifndef TcpThreadUH
#define TcpThreadUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdSocketHandle.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
//---------------------------------------------------------------------------
#include "ObjectU.h"
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
class TTcpThread : public TThread
{
private:
	TApplicationInfo *m_pAppInfo;
	TIdUDPServer *IdUDPServerThr;

private:
	void __fastcall IdUDPServerThrUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding);
	void __fastcall fnTcpOpen();
	void __fastcall fnSendThrData(int a_iCode);
	void __fastcall fnRecvThrData05(TProtocol *a_pRecvPack);
	void __fastcall fnSaveData05(TTcpData05 *a_pRecvData);
	void __fastcall fnSaveData06();
	void __fastcall fnSaveData07();
	void __fastcall fnSendData06(TProtocol *a_pRecvPack);
	void __fastcall fnSendData07(TProtocol *a_pRecvPack);

	void __fastcall fnSendIOData(TProtocol *a_pSendPack);
protected:
	void __fastcall Execute();
public:
	__fastcall TTcpThread(TApplicationInfo *a_pAppInfo);
	__fastcall ~TTcpThread();
};
//---------------------------------------------------------------------------
#endif
