#include "BarCode93.h"



CBarCode93::CBarCode93()
{

}

CBarCode93::CBarCode93(string code)
{
	m_RawData = code;
	InitCode93();
}

CBarCode93::~CBarCode93()
{
}

void CBarCode93::InitCode93()
{
	m_Code93 = new vector<element93*>();
	m_Code93->push_back(new element93("0","0","100010100"));
	m_Code93->push_back(new element93("1", "1", "101001000"));
	m_Code93->push_back(new element93("2", "2", "101000100"));
	m_Code93->push_back(new element93("3", "3", "101000010"));
	m_Code93->push_back(new element93("4", "4", "100101000"));
	m_Code93->push_back(new element93("5", "5", "100100100"));
	m_Code93->push_back(new element93("6", "6", "100100010"));
	m_Code93->push_back(new element93("7", "7", "101010000"));
	m_Code93->push_back(new element93("8", "8", "100010010"));
	m_Code93->push_back(new element93("9", "9", "100001010"));
	m_Code93->push_back(new element93("10", "A", "110101000"));
	m_Code93->push_back(new element93("11", "B", "110100100"));
	m_Code93->push_back(new element93("12", "C", "110100010"));
	m_Code93->push_back(new element93("13", "D", "110010100"));
	m_Code93->push_back(new element93("14", "E", "110010010"));
	m_Code93->push_back(new element93("15", "F", "110001010"));
	m_Code93->push_back(new element93("16", "G", "101101000"));
	m_Code93->push_back(new element93("17", "H", "101100100"));
	m_Code93->push_back(new element93("18", "I", "101100010"));
	m_Code93->push_back(new element93("19", "J", "100110100"));
	m_Code93->push_back(new element93("20", "K", "100011010"));
	m_Code93->push_back(new element93("21", "L", "101011000"));
	m_Code93->push_back(new element93("22", "M", "101001100"));
	m_Code93->push_back(new element93("23", "N", "101000110"));
	m_Code93->push_back(new element93("24", "O", "100101100"));
	m_Code93->push_back(new element93("25", "P", "100010110"));
	m_Code93->push_back(new element93("26", "Q", "110110100"));
	m_Code93->push_back(new element93("27", "R", "110110010"));
	m_Code93->push_back(new element93("28", "S", "110101100"));
	m_Code93->push_back(new element93("29", "T", "110100110"));
	m_Code93->push_back(new element93("30", "U", "110010110"));
	m_Code93->push_back(new element93("31", "V", "110011010"));
	m_Code93->push_back(new element93("32", "W", "101101100"));
	m_Code93->push_back(new element93("33", "X", "101100110"));
	m_Code93->push_back(new element93("34", "Y", "100110110"));
	m_Code93->push_back(new element93("35", "Z", "100111010"));
	m_Code93->push_back(new element93("36", "-", "100101110"));
	m_Code93->push_back(new element93("37", ".", "111010100"));
	m_Code93->push_back(new element93("38", " ", "111010010"));
	m_Code93->push_back(new element93("39", "$", "111001010"));
	m_Code93->push_back(new element93("40", "/", "101101110"));
	m_Code93->push_back(new element93("41", "+", "101110110"));
	m_Code93->push_back(new element93("42", "%", "110101110"));
	m_Code93->push_back(new element93("43", "($)", "100100110"));
	m_Code93->push_back(new element93("44", "(%)", "111011010"));
	m_Code93->push_back(new element93("45", "(/)", "111010110"));
	m_Code93->push_back(new element93("46", "(+)", "100110010"));
	m_Code93->push_back(new element93("47", "*", "101011110"));

}

//计算C检验码
int CBarCode93::CalculateCCheckDigit()   
{
	int iCheckDigit = 0;

	int iPosition = -1;
	int iSum = 0;
    unsigned int iAddress = m_RawData.length();
	string row;

	for (int i = 0; i < m_RawData.length(); i++)
	{
		row = m_RawData[i];
		iPosition = FindCodePosition(row);
		if (iPosition == -1)
			return -1;
		iSum += (iAddress * iPosition);
		iAddress--;
	}
	
	iCheckDigit = iSum % 47;

	return iCheckDigit;;

}

//计算K检验码
int CBarCode93::CalculateKCheckDigit()
{
	int iCheckDigit = 0;
	int iPosition = 0;
	int iSum = 0;

	/*计算C检验码，并加入到字符中*/
	int iC = CalculateCCheckDigit();
	if (iC == -1)
		return -1;
	string CheckCStr = m_Code93->at(iC)->code;  
	m_Encode = m_RawData;
	InsertCheckDigitCode(m_Encode, CheckCStr);

    unsigned int iAddress = m_Encode.length();
	string row = "";
	for (int i = 0; i < m_Encode.length(); i++)
	{
		row = m_Encode[i];
		iPosition = FindCodePosition(row);
		if (iPosition == -1)
			return -1;
		iSum += (iAddress * iPosition);
		iAddress--;
	}
	iCheckDigit = iSum % 47;

	return iCheckDigit;
}


int CBarCode93::FindCodePosition(string s)
{
	if (s.empty())
	{
		return -1;
	}

	for (int i = 0; i < m_Code93->size(); i++)
	{
		if (m_Code93->at(i)->code == s)
		{
			return i;
		}
	}
	return -1;
}

//插入检验码
void CBarCode93::InsertCheckDigitCode(string &Encode,string s)
{
	if (s.empty())
	{
		return;
	}

	Encode.append(s);
}

string CBarCode93::GetEncoding()
{
	if (m_RawData.empty())
		return string();

	StringToUpper(m_RawData);

	//将K检验码加入字符中
	int iCheckDigit = CalculateKCheckDigit();
	if (iCheckDigit == -1)
		return "";
	string k_str = m_Code93->at(iCheckDigit)->code;
	InsertCheckDigitCode(m_Encode, k_str);


	string row = "";
	string code = "";
	int iPosition = -1;
	for (int i = 0; i < m_Encode.length(); i++)  //获取字符编码
	{
		row = m_Encode[i];
		iPosition = FindCodePosition(row);
		if (iPosition == -1)
			return "";

		code += (m_Code93->at(iPosition)->enconding);
	}
	//插入起始编码、结束编码、停止位
	code.insert(0, m_Code93->back()->enconding);
	code.append(m_Code93->back()->enconding);
	code.append("1");

	return code;
}

//将小写转大写字母
void CBarCode93::StringToUpper(string &str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

string CBarCode93::text()const
{
	return m_RawData;
}
