//---------------------------------------------------------------------------

#pragma hdrstop

#include "TcpCommU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TTcpBase::TTcpBase()
{
}
//---------------------------------------------------------------------------
__fastcall TTcpBase::~TTcpBase()
{
}
//---------------------------------------------------------------------------
int __fastcall TTcpBase::fnDefaultEncoding(BYTE *pBuffer, int &iIndex, void *pData, int iDataSize)
{
	if(iIndex + iDataSize > MAX_TCP_BUFFER) return 11;
	CopyMemory(pBuffer+iIndex, pData, iDataSize);             //	(버퍼에 헤더사이즈만큼 이동한위치에 pData를 iDataSize만큼 복사)
	iIndex += iDataSize;                                      // 	(iDataSize만큼 인덱스 증가)
	return 0;
}
//---------------------------------------------------------------------------
int __fastcall TTcpBase::fnDefaultDecoding(BYTE *pBuffer, int &iIndex, int iSize, void *pData, int iDataSize)
{
	if(iIndex + iDataSize > iSize) return 11;
	CopyMemory(pData, pBuffer+iIndex, iDataSize);
	iIndex += iDataSize;
	return 0;
}
//---------------------------------------------------------------------------
__fastcall TProtocol::TProtocol()
{
	ZeroMemory(&m_stHeader, sizeof(m_stHeader));
	ZeroMemory(&m_stTail, 	sizeof(m_stTail));

	m_stHeader.bySTX1 = 0x10;
	m_stHeader.bySTX2 = 0x02;

	m_stTail.byETX1	  = 0x10;
	m_stTail.byETX1	  = 0x03;
}
//---------------------------------------------------------------------------
__fastcall TProtocol::~TProtocol()
{
}
//---------------------------------------------------------------------------
void __fastcall TProtocol::fnSetDataLen(int a_iValue)
{
	m_iDataLen = a_iValue;
	m_stHeader.wDataLen	= a_iValue;
}
//---------------------------------------------------------------------------
int __fastcall TProtocol::fnGetDataLen()
{
	return m_iDataLen;
}
//---------------------------------------------------------------------------
int __fastcall TProtocol::fnEncoding()
{
	int iResult = 0;
	m_iSendPackSize = 0;
	ZeroMemory(m_bySendPacket, sizeof(m_bySendPacket));                      //	보낼 패킷버퍼 초기화
	m_iSendPackSize += sizeof(m_stHeader);                                   //	보낼 패킷사이즈에 헤더크기 추가
	DataLen = 0;                                                             //	(m_stHeader.byDataLen 부분 초기화)

	switch (Code) {
		case 0x05:	{
			TTcpData05 *pData = (TTcpData05*)m_pBody;
			DataLen = pData->DataLen;											 //	Data05의 데이터 사이즈 반환
			iResult = pData->fnEncodingBody(m_bySendPacket, m_iSendPackSize);
			break;
			}
		case 0x06:	{
			TTcpData06 *pData = (TTcpData06*)m_pBody;
			DataLen = pData->DataLen;											 //	Data06의 데이터 사이즈 반환
			iResult = pData->fnEncodingBody(m_bySendPacket, m_iSendPackSize);
			break;
			}
		case 0x07:	{
			TTcpData07 *pData = (TTcpData07*)m_pBody;
			DataLen = pData->DataLen;											 //	Data07의 데이터 사이즈 반환
			iResult = pData->fnEncodingBody(m_bySendPacket, m_iSendPackSize);
			break;
			}
		default:	{
			break;
			}
	}
	if (iResult == 0) {
		CopyMemory(m_bySendPacket, &m_stHeader, sizeof(m_stHeader));
	}
	return iResult;




}
//---------------------------------------------------------------------------

__fastcall TTcpData05::TTcpData05()
{
	ZeroMemory(&m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------
__fastcall TTcpData05::~TTcpData05()
{
}
//---------------------------------------------------------------------------
int __fastcall TTcpData05::fnGetDataLen()
{
	return sizeof(m_stData);
}
//---------------------------------------------------------------------------
int __fastcall TTcpData05::fnEncodingBody(BYTE *a_pBuffer, int &a_iIndex)
{
	return fnDefaultEncoding(a_pBuffer, a_iIndex, &m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------
__fastcall TTcpData06::TTcpData06()
{
	ZeroMemory(&m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------
__fastcall TTcpData06::~TTcpData06()
{
}
//---------------------------------------------------------------------------
int __fastcall TTcpData06::fnGetDataLen()
{
	return sizeof(m_stData);
}
//---------------------------------------------------------------------------
int __fastcall TTcpData06::fnEncodingBody(BYTE *a_pBuffer, int &a_iIndex)
{
	return fnDefaultEncoding(a_pBuffer, a_iIndex, &m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------
__fastcall TTcpData07::TTcpData07()
{
	ZeroMemory(&m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------
__fastcall TTcpData07::~TTcpData07()
{
}
//---------------------------------------------------------------------------
int __fastcall TTcpData07::fnGetDataLen()
{
	return sizeof(m_stData);
}
//---------------------------------------------------------------------------
int __fastcall TTcpData07::fnEncodingBody(BYTE *a_pBuffer, int &a_iIndex)
{
	return fnDefaultEncoding(a_pBuffer, a_iIndex, &m_stData, sizeof(m_stData));
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//void __fastcall TProtocol::fnSetOpCode(int a_op)
//{
//	m_stHeader.byOpCode = a_op;
//}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
