#pragma once
/**
*\brief
*功能: BarCode128类型条码生成
*时间: 2019-5-24
*Editor: Mr.Wu

*Modified: 修改Auto类型编码不能正确扫描问题，增加编码转换符功能。
*Time: 2019-7-12

*/


#ifndef CBARCODE128_H
#define CBARCODE128_H

#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

using namespace std;


/**
*\brief
*条码类型
*A = Code128A,
*B = Code128B,
*C = Code128C,
*/
enum TYPES             
{
	DYNAMIC,
	A,
	B,
	C
};


/**
*\brief
*COLUMN_VALUE : 条码列值
*COLUMN_A: A列
*COLUMN_B: B列
*COLUMN_C: C列
*COLUMN_ENCODING: 编码
*/
enum COLUMN
{
	COLUMN_VALUE,
	COLUMN_A,
	COLUMN_B,
	COLUMN_C,
	COLUMN_ENCODING
};

struct element_t
{
	string Value;
	string A;
	string B;
	string C;
	string Encoding;
    element_t() {}
	element_t(string value, string a, string b, string c, string encoding) :
		Value(value), A(a), B(b), C(c), Encoding(encoding) {}
};


struct BarCodeInfo
{
	int        iType;       //条码类型
	string     sText;       //条码内容
	bool       bReverse;
};


class  CBarCode128
{
public:
	CBarCode128(string);
	CBarCode128(string, TYPES);

	~CBarCode128();
	

    /**
	*\brief
	*获取编码
	*/
    string GetEncoding();

	string SetReverse(string);

	/**
	*\brief
	*设置文本内容
	*/
	void SetText(string text);

	/**
	*\brief
	*获取文本内容
	*/
	string GetText()const;

public:
	BarCodeInfo m_CodeInfo;

private:
	string m_Raw_Data;         //原始数据
	
	string m_Encoded_Data;       //编码数据
	
	TYPES m_Type;
	
	element_t m_StartCharacter;        //起始特点
	
	vector<element_t*>* m_C128_Code;    //128编码元素

	vector<string> m_FormattedData;     //数据格式

	string m_ErrorMsg;              //错误消息

	//A,B,C,起始元素
	element_t   m_startAElement;
	element_t   m_startBElement;
	element_t   m_startCElement;

	//A,B,C条码元素
	element_t   m_codeAElement;
	element_t   m_codeBElement;
	element_t   m_codeCElement;
	
	//停止码
	element_t   m_codeStop;


private:
	/**
	*\brief
	*初始化128条码,  string: 原始数据, TYPES: 条码类型
	*/
	void Init_Code128(string, TYPES);

	/**
	*\brief
	*计算检验位
	*/
	string CalculateCheckDigit();

	/**
	*\brief
	*分析数据进行编码
	*/
	void BreakUpDataForEncoding();

	/**
	*\brief
	*在起始位后插入编码
	*/
	void InsertStartandCodeCharacter();

	/**
	*\brief
	*DYNAMIC 编码类型，插入编码转换符
	*/
	void InsertAutoControlCode();

	/**
	*\brief
	*查找代码字符
	*/
	vector<element_t> FindStartorCodeCharacter(string, int &);

	/**
	*\brief
	*查找原始字符编码
	*/
	int FindCharEncodingRow(COLUMN, string);

	
	char* IntToAlpha(int value, char *result, int base);

	/**
	*\brief
	*128C 字符判断，128C:是否为数字
	*/
	bool isNumber(const string&);

	void Error(string);


};


#endif // CBARCODE128_H



