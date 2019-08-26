#include "BarCode39.h"
#include <iostream>
#include <algorithm>



CBarCode39::CBarCode39()
{
}

CBarCode39::CBarCode39(string text)
{
	m_RawData = text;

	InitCode();
}

CBarCode39::~CBarCode39()
{
}


void CBarCode39::InitCode()
{
	m_Encoding = new vector<element39*>();
	m_Encoding->push_back(new element39("0", "0", "101001101101"));  
	m_Encoding->push_back(new element39("1", "1", "110100101011"));
	m_Encoding->push_back(new element39("2", "2", "101100101011"));
	m_Encoding->push_back(new element39("3", "3", "110110010101"));
	m_Encoding->push_back(new element39("4", "4", "101001101011"));
	m_Encoding->push_back(new element39("5", "5", "110100110101"));
	m_Encoding->push_back(new element39("6", "6", "101100110101"));
	m_Encoding->push_back(new element39("7", "7", "101001011011"));
	m_Encoding->push_back(new element39("8", "8", "110100101101"));
	m_Encoding->push_back(new element39("9", "9", "101100101101"));
	m_Encoding->push_back(new element39("10", "A", "110101001011"));
	m_Encoding->push_back(new element39("11", "B", "101101001011"));
	m_Encoding->push_back(new element39("12", "C", "110110100101"));
	m_Encoding->push_back(new element39("13", "D", "101011001011"));
	m_Encoding->push_back(new element39("14", "E", "110101100101"));
	m_Encoding->push_back(new element39("15", "F", "101101100101"));
	m_Encoding->push_back(new element39("16", "G", "101010011011"));
	m_Encoding->push_back(new element39("17", "H", "110101001101"));
	m_Encoding->push_back(new element39("18", "I", "101101001101"));
	m_Encoding->push_back(new element39("19", "J", "101011001101"));
	m_Encoding->push_back(new element39("20", "K", "110101010011"));
	m_Encoding->push_back(new element39("21", "L", "101101010011"));
	m_Encoding->push_back(new element39("22", "M", "110110101001"));
	m_Encoding->push_back(new element39("23", "N", "101011010011"));
	m_Encoding->push_back(new element39("24", "O", "110101101001"));
	m_Encoding->push_back(new element39("25", "P", "101101101001"));
	m_Encoding->push_back(new element39("26", "Q", "101010110011"));
	m_Encoding->push_back(new element39("27", "R", "110101011001"));
	m_Encoding->push_back(new element39("28", "S", "101101011001"));
	m_Encoding->push_back(new element39("29", "T", "101011011001"));
	m_Encoding->push_back(new element39("30", "U", "110010101011"));
	m_Encoding->push_back(new element39("31", "V", "100110101011"));
	m_Encoding->push_back(new element39("32", "W", "110011010101"));
	m_Encoding->push_back(new element39("33", "X", "100101101011"));
	m_Encoding->push_back(new element39("34", "Y", "110010110101"));
	m_Encoding->push_back(new element39("35", "Z", "100110110101"));
	m_Encoding->push_back(new element39("36", "+", "100101001001"));
	m_Encoding->push_back(new element39("37", "-", "100101011011"));
	m_Encoding->push_back(new element39("38", " ", "100110101101"));
	m_Encoding->push_back(new element39("39", "/", "100100101001"));
	m_Encoding->push_back(new element39("40", "%", "101001001001"));
	m_Encoding->push_back(new element39("41", "$", "110010101101"));
	m_Encoding->push_back(new element39("42", ".", "101100101011"));
	m_Encoding->push_back(new element39("43", "*", "100101101101"));
}

//取得code39 字符编码
string CBarCode39::GetEncode39()
{
	string rawdata = m_RawData;	
	StringToUpper(rawdata);

	//rawdata.insert(0, "*");
	//rawdata.push_back('*');

	string cstr;
	int ind = 0;
	string strgap = "0";  //间隔符
	string encode;
	for (int i = 0; i < rawdata.length(); i++)   //查找字符编码
	{
		cstr = rawdata[i];
		

		ind = FindCodePosition(cstr);
		if (ind == -1)
			return "";
		encode += (m_Encoding->at(ind)->encoding);
	}
	encode.insert(0, m_Encoding->back()->encoding);  //插入起始、结束符
	encode.append(m_Encoding->back()->encoding);

	size_t length = encode.length();
	for (int i = 0; i < length;)
	{
		i += 12;
		encode.insert(i, "0");   //在每一位字符编码后加空条
		i++;
	}

	return encode;
}

int CBarCode39::FindCodePosition(string s)
{
	if (s.empty())
		return -1;

	for (int i = 0; i < m_Encoding->size(); i++)
	{
		if (m_Encoding->at(i)->code39 == s)
		{
			return i;
		}
	}
	return -1;
}

//将小写转大写字母
void CBarCode39::StringToUpper(string &str)
{
	std::transform(str.begin(), str.end(),str.begin(), ::toupper);
}

string CBarCode39::text()const
{
	return m_RawData;
}
