#include "BarCode.h"
#include "BarCode128.h"
#include "BarCode39.h"
#include "BarCode93.h"
#include "BarCodeEAN13.h"


CBarCode::CBarCode(string text,BARCODE_TYPE iType)
{
	m_RawData = text; 
    m_Type = iType;

	m_CodeInfo.bReverse = false;
	m_CodeInfo.sText = text;
	m_CodeInfo.dHeight = (double)30.00;
    m_CodeInfo.iType = iType;
	m_CodeInfo.bHideText = false;
}

CBarCode::CBarCode(string text, BARCODE_TYPE iType, CodeInfo info)
{
	m_RawData = text;
	m_Type = iType;

	m_CodeInfo.sText = info.sText;
	m_CodeInfo.dHeight = info.dHeight;
    m_CodeInfo.iType = iType;
	m_CodeInfo.bReverse = info.bReverse;
	m_CodeInfo.bHideText = false;


}

CBarCode::~CBarCode()
{
}

string CBarCode::CreateBarCode()
{
	string encode;
	if (m_CodeInfo.iType == CODE128A)
	{
		m_128Code = new CBarCode128(m_RawData, A);
		encode = m_128Code->GetEncoding();

		delete m_128Code;
		m_128Code = nullptr;
	}
	else if (m_CodeInfo.iType == CODE128B)
	{
		m_128Code = new CBarCode128(m_RawData, B);
		encode = m_128Code->GetEncoding();

		delete m_128Code;
		m_128Code = nullptr;
	}
	else if (m_CodeInfo.iType == CODE128C)
	{
		m_128Code = new CBarCode128(m_RawData, C);
		encode = m_128Code->GetEncoding();

		delete m_128Code;
		m_128Code = nullptr;
	}
    else if(m_CodeInfo.iType == CODE128AUTO)
    {
        m_128Code = new CBarCode128(m_RawData, DYNAMIC);
        encode = m_128Code->GetEncoding();

        delete m_128Code;
        m_128Code = nullptr;
    }
	else if (m_CodeInfo.iType == CODE39)
	{
		m_39Code = new CBarCode39(m_RawData);
		encode = m_39Code->GetEncode39();

		delete m_39Code;
		m_39Code = nullptr;
	}
	else if (m_CodeInfo.iType == CODE93)
	{
		m_93Code = new CBarCode93(m_RawData);
		encode = m_93Code->GetEncoding();

		delete m_93Code;
		m_93Code = nullptr;
	}
	else if (m_CodeInfo.iType == CODEEAN13)
	{
		m_EAN13 = new CBarCodeEAN13(m_RawData);
		encode = m_EAN13->GetEncode();

		delete m_EAN13;
		m_EAN13 = nullptr;
	}

    if (m_CodeInfo.bReverse)   //反转条码
        {
            string ReverseStr = ReverseCode(encode);
            return ReverseStr;
        }

	return encode;
}

void CBarCode::GetCodeInfo(CodeInfo &info)
{
	info.bReverse = m_CodeInfo.bReverse;
	info.dHeight = m_CodeInfo.dHeight;
	info.iType = m_CodeInfo.iType;
	info.sText = m_CodeInfo.sText;
}

void CBarCode::SetCodeInfo(CodeInfo info)
{
	m_CodeInfo = info;
	
    if(m_CodeInfo.iType == -1)
    {
        m_CodeInfo.iType = CODE128B;
    }
	m_CodeInfo.sText = info.sText;
}

string CBarCode::ReverseCode(string str)
{
    if (str.empty())
        return "";
    if (m_CodeInfo.bReverse)
    {
        string ReverseStr;
        string ch;
        for ( int i = str.size() - 1 ; i >= 0; i--)
        {
            ch = str.at(i);
            ReverseStr.append(ch);
        }
        return ReverseStr;
    }
    return "";
}
