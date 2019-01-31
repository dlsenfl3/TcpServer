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
	void __fastcall fnSendThrData();
	void __fastcall fnRecvThrData05(TProtocol *a_pRecvPack);
	void __fastcall fnSaveData05(TTcpData05 *a_pRecvData);

protected:
	void __fastcall Execute();
public:
	__fastcall TTcpThread(TApplicationInfo *a_pAppInfo);
	__fastcall ~TTcpThread();
};
//---------------------------------------------------------------------------
#endif
