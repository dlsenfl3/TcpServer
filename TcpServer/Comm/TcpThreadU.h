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
//---------------------------------------------------------------------------
class TTcpThread : public TThread
{
private:
	TApplicationInfo *m_pAppInfo;
	TIdUDPServer *IdUDPServer;

private:
	void __fastcall IdUDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding);

protected:
	void __fastcall Execute();
public:
	__fastcall TTcpThread(TApplicationInfo *a_pAppInfo);
	__fastcall ~TTcpThread();
};
//---------------------------------------------------------------------------
#endif
