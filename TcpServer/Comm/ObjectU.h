//---------------------------------------------------------------------------

#ifndef ObjectUH
#define ObjectUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>			//추가한 헤더
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TcpCommU.h"
//---------------------------------------------------------------------------
// WM_USER == 0x400 ( 0x0400 ~ 0x7fff ) 사용자 메시지 영역
//---------------------------------------------------------------------------
#define WM_TCP_OPEN						(WM_USER + 0x01)
#define WM_SEND_TEST                   	(WM_USER + 0x03)

#define WM_TCP_RECV05                   (WM_USER + 0x05)
#define WM_TCP_SAVE06                   (WM_USER + 0x06)
#define WM_TCP_SAVE07                   (WM_USER + 0x07)



//---------------------------------------------------------------------------
class TStatusInfo
{
private:
	TTcpData05 *m_TData05;
	TTcpData06 *m_TData06;
	TTcpData07 *m_TData07;
public:
	__fastcall 	TStatusInfo();
	__fastcall ~TStatusInfo();
public:
	__property TTcpData05*	TcpData05	= {read = m_TData05		, write = m_TData05};
	__property TTcpData06*	TcpData06	= {read = m_TData06		, write = m_TData06};
	__property TTcpData07*	TcpData07	= {read = m_TData07		, write = m_TData07};
};
//---------------------------------------------------------------------------
class TApplicationInfo
{
private:
	TStatusInfo *m_pStatusInfo;
	int 		 m_iIp;
	int 		 m_iPort;
	DWORD 		 m_dwTcpThrd;
public:
	__fastcall 	TApplicationInfo();
	__fastcall ~TApplicationInfo();
public:
	__property	TStatusInfo*	Status		= {read = m_pStatusInfo	,	 write = m_pStatusInfo};
	__property  int				Ip			= {read = m_iIp			,	 write = m_iIp	   	  };
	__property  int				Port		= {read = m_iPort		,	 write = m_iPort	  };
	__property  DWORD			ThreadId	= {read = m_dwTcpThrd	,	 write = m_dwTcpThrd  };
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
