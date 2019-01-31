//---------------------------------------------------------------------------

#pragma hdrstop

#include "ObjectU.h"
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TStatusInfo::TStatusInfo()
{
	m_TData05 = new TTcpData05();
	m_TData06 = new TTcpData06();
	m_TData07 = new TTcpData07();
}
//---------------------------------------------------------------------------
__fastcall TStatusInfo::~TStatusInfo()
{
	delete m_TData05;
	delete m_TData06;
	delete m_TData07;
}
//---------------------------------------------------------------------------
__fastcall 	TApplicationInfo::TApplicationInfo()
{
	m_pStatusInfo = new TStatusInfo();
	AnsiString sPath;
	sPath	   	  = ExtractFilePath(Application->ExeName) + "TcpServer_Project.ini";
	TIniFile* pIni = new TIniFile(sPath);
	//	IP, PORT 초기화
	m_iIp	= pIni->ReadString ("APP", "IPAddress"	, 0);
	m_iPort	= pIni->ReadInteger("APP", "Port"		, 0);

	//	Data05 Memory로드
	m_pStatusInfo->TcpData05->ModulPower          = pIni->ReadInteger("DATA05", "ModulPower"           	, 0);
	m_pStatusInfo->TcpData05->ResetTime	          = pIni->ReadInteger("DATA05", "ResetTime"            	, 0);
	m_pStatusInfo->TcpData05->TryCount	          = pIni->ReadInteger("DATA05", "TryCount"	           	, 0);
	m_pStatusInfo->TcpData05->ControlTime         = pIni->ReadString ("DATA05", "ControlTime"	       	, 0); // ReadString
	m_pStatusInfo->TcpData05->RunTime	          = pIni->ReadString ("DATA05", "RunTime"		       	, 0); // ReadString
	m_pStatusInfo->TcpData05->BlinkCycle          = pIni->ReadInteger("DATA05", "BlinkCycle"	       	, 0);
	m_pStatusInfo->TcpData05->ScinarioRunTime     = pIni->ReadInteger("DATA05", "ScinarioRunTime"      	, 0);
	m_pStatusInfo->TcpData05->BrightControl1	  = pIni->ReadInteger("DATA05", "BrightControl1"	    , 0); // 제어값 0수동 1자동
	m_pStatusInfo->TcpData05->BrightControl2	  = pIni->ReadInteger("DATA05", "BrightControl2"	    , 0); // 밝기   수동일때 0~100, 자동일때 0
	m_pStatusInfo->TcpData05->FanControl	      = pIni->ReadInteger("DATA05", "FanControl"	       	, 0);
	m_pStatusInfo->TcpData05->HeaterControl	      = pIni->ReadInteger("DATA05", "HeaterControl"	       	, 0);
	m_pStatusInfo->TcpData05->LampControl	      = pIni->ReadInteger("DATA05", "LampControl"	       	, 0);
	m_pStatusInfo->TcpData05->LedControl	      = pIni->ReadInteger("DATA05", "LedControl"	       	, 0);
	//	Data06 Memory로드
	m_pStatusInfo->TcpData06->Door	    	      = pIni->ReadInteger("DATA06", "Door"	    	      	, 0);
	m_pStatusInfo->TcpData06->Power	      	      = pIni->ReadInteger("DATA06", "Power"	      	     	, 0);
	m_pStatusInfo->TcpData06->Fan	    	      = pIni->ReadInteger("DATA06", "Fan"	    	       	, 0);
	m_pStatusInfo->TcpData06->Heater	          = pIni->ReadInteger("DATA06", "Heater"	         	, 0);
	m_pStatusInfo->TcpData06->OuterLight	      = pIni->ReadInteger("DATA06", "OuterLight"	     	, 0);
	m_pStatusInfo->TcpData06->FormKind	          = pIni->ReadInteger("DATA06", "FormKind"	         	, 0);
	m_pStatusInfo->TcpData06->ReplayCheck	      = pIni->ReadInteger("DATA06", "ReplayCheck"	     	, 0);
	m_pStatusInfo->TcpData06->PowerOdd	          = pIni->ReadInteger("DATA06", "PowerOdd"	         	, 0);
	m_pStatusInfo->TcpData06->ModulOdd	          = pIni->ReadInteger("DATA06", "ModulOdd"	         	, 0);
	m_pStatusInfo->TcpData06->Temperature	      = pIni->ReadInteger("DATA06", "Temperature"	     	, 0);
	m_pStatusInfo->TcpData06->DisplayBright       = pIni->ReadInteger("DATA06", "DisplayBright"	     	, 0);
	m_pStatusInfo->TcpData06->Etc2	    	      = pIni->ReadInteger("DATA06", "Etc2"	    	     	, 0);
	//	Data07 Memory로드
	m_pStatusInfo->TcpData07->PowerMode	      	  = pIni->ReadInteger("DATA07", "PowerMode"	     		, 0);
	m_pStatusInfo->TcpData07->Fan	    		  = pIni->ReadInteger("DATA07", "Fan"	    		 	, 0);
	m_pStatusInfo->TcpData07->FanTemper	      	  = pIni->ReadInteger("DATA07", "FanTemper"	      		, 0);
	m_pStatusInfo->TcpData07->Heater	    	  = pIni->ReadInteger("DATA07", "Heater"	    		, 0);
	m_pStatusInfo->TcpData07->HeaterTemper	   	  = pIni->ReadInteger("DATA07", "HeaterTemper"	   		, 0);
	m_pStatusInfo->TcpData07->DisplayBright	      = pIni->ReadInteger("DATA07", "DisplayBright"	  		, 0);
	m_pStatusInfo->TcpData07->FlashCycle	      = pIni->ReadInteger("DATA07", "FlashCycle"	    	, 0);
	m_pStatusInfo->TcpData07->OuterLightOperating = pIni->ReadInteger("DATA07", "OuterLightOperating"	, 0);
	m_pStatusInfo->TcpData07->OuterLightOnBright  = pIni->ReadInteger("DATA07", "OuterLightOnBright" 	, 0);
	m_pStatusInfo->TcpData07->Scenario	    	  = pIni->ReadInteger("DATA07", "Scenario"	    		, 0);
	m_pStatusInfo->TcpData07->Etc1	  			  = pIni->ReadInteger("DATA07", "Etc1"	  				, 0);
	m_pStatusInfo->TcpData07->Etc2	    		  = pIni->ReadInteger("DATA07", "Etc2"	    			, 0);

	delete pIni;
}
//---------------------------------------------------------------------------
__fastcall 	TApplicationInfo::~TApplicationInfo()
{
	delete m_pStatusInfo;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
