#pragma once
#ifndef CBARCODE_H
#define CBARCODE_H
/*
*\brief
*功能: 把所有条码类型做封装，方便调用
*时间: 2019-5-30
*Editor: Mr.Wu
*/

#include <vector>
#include <string>
using namespace std;

class CBarCode39;
class CBarCode93;
class CBarCode128;
class CBarCodeEAN13;


enum BARCODE_TYPE
{
	CODE128AUTO,
	CODE128A,
	CODE128B,
	CODE128C,    
    CODE39,
	CODE93,
	CODEEAN13
};


/**
*\brief
*条码信息
*/
struct CodeInfo
{
	double   dHeight;
	BARCODE_TYPE      iType;
	string   sText;
	bool     bReverse;
	bool     bHideText;
};


/**
*\brief
*所有条码类型集合。
*创建条码编码，使用此类来创建。
*根据类型，来创建。
*/
class  CBarCode
{
public:
    CBarCode(string text,BARCODE_TYPE iType = CODE128AUTO);
	CBarCode(string text, BARCODE_TYPE iType, CodeInfo info);
	~CBarCode();

	/**
	*\brief
	*创建条码
	*/
	string CreateBarCode();

	/**
	*\brief
	*获取条码信息
	*/
	void GetCodeInfo(CodeInfo &info);

	/**
	*\brief
	*设置条码信息
	*/	
	void SetCodeInfo(CodeInfo info);


    /**
	*\brief
	*设置条码反转
	*/
     string ReverseCode(string str);

      CodeInfo      m_CodeInfo;         //存储条码信息
private:

	CBarCode128   *m_128Code;         //128条码
	CBarCode39    *m_39Code;          //39条码
	CBarCode93    *m_93Code;          //93条码
	CBarCodeEAN13 *m_EAN13;

	string        m_RawData;          //原始数据，条码文本
	BARCODE_TYPE           m_Type;             //条码类型
};

#endif // !CBARCODE_H



