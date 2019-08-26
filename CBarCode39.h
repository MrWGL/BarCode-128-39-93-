#pragma once
/*
功能:  BarCode39条码生成
时间:  2019-5-27
Editor:  Mr.Wu
*/

#ifndef CBARCODE39
#define CBARCODE39

#include "BarCodeItem/barcodelib_global.h"
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;


/**
*\brief
*编码元素,存储了编码值，及编码索引，
*/
struct element39
{
	string value;
	string code39;
	string encoding;

	element39(){}
	element39(string svalue,string scode39,string sencoding):
		value(svalue),code39(scode39),encoding(sencoding){}
};

class BARCODELIB_EXPORT CBarCode39
{
public:
	CBarCode39(string);
	CBarCode39();
	~CBarCode39();

	/**
	*\brief
	*获取字符编码
	*/
	string GetEncode39();

	/**
	*\brief
	*初始化BarCode39
	*/
	void InitCode();

	/**
	*\brief
	*查找字符位置编码
	*/
	int FindCodePosition(string s);

	string text()const;

private:
	string     m_RawData;                //原始内容

	vector<element39*>*  m_Encoding;               //字符编码集

	vector<string>   m_FormatData;

private:
	/**
	*\brief
	*字符转换，全部转换成大写
	*/
	void StringToUpper(string &str);
};


#endif // !CBARCODE39




