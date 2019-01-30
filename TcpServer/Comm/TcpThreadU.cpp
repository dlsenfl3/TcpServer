//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TcpThreadU.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TcpThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TTcpThread::TTcpThread(TApplicationInfo *a_pAppInfo)
	: TThread(true)		// false 이면 생성된 직후에 바로 실행.
{
	m_pAppInfo = a_pAppInfo;
	IdUDPServer = new TIdUDPServer();
	IdUDPServer->OnUDPRead = IdUDPServerUDPRead;

	Priority 		= tpNormal;
	FreeOnTerminate = true;                            //	??
	Suspended		= false;                           //	??
}
//---------------------------------------------------------------------------
__fastcall TTcpThread::~TTcpThread()
{
	delete m_pAppInfo;
	delete IdUDPServer;
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::Execute()
{
	MSG stMsg;                                           // 메인폼에서 보낸 메세지를 받을 그릇
	while(!Terminated){                                  //	Terminated는 속성으로서 현재 쓰레드가 작업중인지의 여부를 가리키는 boolean형 속성
		try{
			if(GetMessage(&stMsg, NULL, 0, 0) == 0){
				Terminate();                             //	메세지의 값이 0이면(메세지가 없으면)
			}else{
				switch(stMsg.message){
//					case WM_ACP_OPEN:                    //	메세지가 WM_ACP_OPEN이면
//					fnAcpOpen();
					break;
				}
			}
		}
		catch(Exception& E){
			OutputDebugString(E.Message.c_str());
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTcpThread::IdUDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{

}
//---------------------------------------------------------------------------
