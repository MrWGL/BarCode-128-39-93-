#pragma once
/*
功能: BarCode93条码生成
时间: 2019-5-28
Editor: Mr.Wu
*/


#ifndef CBARCODE93
#define CBARCODE93

#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include"BarCodeItem/barcodelib_global.h"

using namespace std;

struct element93
{
	string value;
	string code;
	string enconding;
	element93(){}
	element93(string svalue,string scode,string sencode):
		value(svalue),code(scode),enconding(sencode){}
};

class BARCODELIB_EXPORT CBarCode93
{
public:
	CBarCode93();
	CBarCode93(string);
	~CBarCode93();

	/**
	*\brief
	*获取BarCode93编码
	*/
	string GetEncoding();
	
	/**
	*\brief
	*将文本转大写字母
	*/
	void StringToUpper(std::string &text);

	string text()const;

public:
	/**
	*\brief
	*初始化编码
	*/
	void InitCode93();

	/**
	*\brief
	*计算C检验码
	*/
	int CalculateCCheckDigit();

	/**
	*\brief
	*计算K检验码
	*/
	int CalculateKCheckDigit();

	/**
	*\brief
	*在初始化编码中,查找字符位置，返回字符位置
	*/
	int FindCodePosition(string s);

	/**
	*\brief
	*插入检验码,返回一个新的字符串
	*/
	void InsertCheckDigitCode(string &currentstr,string s);

private:
	vector<element93*> *m_Code93;   //字符编码表

	string m_RawData;       //原始数据

	string m_Encode;        //加上检验码后的字符
};


#endif // !CBARCODE93



