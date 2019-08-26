#pragma once
/*
Function: EAN-13Code
Timer: 2019-07-24
Editor: Mr.Wu
*/
#include <string>
#include <vector>
using namespace std;

/**
*\brief
*EAN 三种类型编码
*A B C
*/

enum EAN_TYPE
{
	ENCODEA,
	ENCODEB,
	ENCODEC
};


/**
*\brief
*编码元素：
*LeftCode:使用的字符编码类型
*LeftACode: A 字符集编码
*LeftBCode: B 字符集编码
*RightCode: C 字符集编码
*/
struct element13
{
	string LeftCode;
	string LeftACode;
	string LeftBCode;
	string RightCode;
	string Value;

	element13(string value, string leftcode, string leftA, string leftB, string right)
		: Value(value), LeftCode(leftcode), LeftACode(leftA), LeftBCode(leftB), RightCode(right)
	{	}
};


class  CBarCodeEAN13
{
public:
	CBarCodeEAN13(string str);
	~CBarCodeEAN13();


	/**
	*\brief
	*计算检验码	
	*/
	int CalculateCheckDigit();

	/**
	*\brief
	*获取 EAN13 编码
	*/
	string GetEncode();
private:
	/**
	*\brief
	*初始化编码集
	*/
	void InitEncode();

	/**
	*\brief
	*查找字符编码，在编码集中查找与文本对应的编码
	*/
	void FindCharacterrCode();


	/**
	*\brief
	*当前文本是否为数字
	*/
	bool isNumber(const string &s);

	/**
	*\brief
	*查找起始位字符编码，返回使用的编码类型
	*/
	string FindStartEncode(string &s);

	/**
	*\brief
	*在编码集中查找对应的字符编码:
	*s: 查找字符
	*type: 查找类型，在A B C三个编码类型中找
	*/
	string FindDataEncode(string &s, EAN_TYPE type);
private:
	string m_Text;
	vector<element13*>  *m_EAN13_Code;
	string m_MidCode;                //middle code
	string m_AuxiliaryCode;
	string m_Encode;
};

