#include "BarCode128.h"
#include <iostream>
#include <iosfwd>


CBarCode128::CBarCode128(string toEncode)
{
	CBarCode128(toEncode, DYNAMIC);
}

CBarCode128::CBarCode128(string toEncode, TYPES type)
{
	m_Raw_Data = toEncode;
	Init_Code128(toEncode, type);
	
	m_CodeInfo.sText = m_Raw_Data;
	m_CodeInfo.iType = type;
	m_CodeInfo.bReverse = false;

}


CBarCode128::~CBarCode128()
{
	
}

void CBarCode128::Init_Code128(string toEncode, TYPES type)
{
	m_Raw_Data = toEncode;
	m_Type = type;

	m_ErrorMsg = "";
	m_Encoded_Data = "";

	m_C128_Code = new vector<element_t*>();
	m_C128_Code->push_back(new element_t("0", " ", " ", "00", "11011001100"));
	m_C128_Code->push_back(new element_t("1", "!", "!", "01", "11001101100"));
	m_C128_Code->push_back(new element_t("2", "\"", "\"", "02", "11001100110"));
	m_C128_Code->push_back(new element_t("3", "#", "#", "03", "10010011000"));
	m_C128_Code->push_back(new element_t("4", "$", "$", "04", "10010001100"));
	m_C128_Code->push_back(new element_t("5", "%", "%", "05", "10001001100"));
	m_C128_Code->push_back(new element_t("6", "&", "&", "06", "10011001000"));
	m_C128_Code->push_back(new element_t("7", "'", "'", "07", "10011000100"));
	m_C128_Code->push_back(new element_t("8", "(", "(", "08", "10001100100"));
	m_C128_Code->push_back(new element_t("9", ")", ")", "09", "11001001000"));
	m_C128_Code->push_back(new element_t("10", "*", "*", "10", "11001000100"));
	m_C128_Code->push_back(new element_t("11", "+", "+", "11", "11000100100"));
	m_C128_Code->push_back(new element_t("12", ",", ",", "12", "10110011100"));
	m_C128_Code->push_back(new element_t("13", "-", "-", "13", "10011011100"));
	m_C128_Code->push_back(new element_t("14", ".", ".", "14", "10011001110"));
	m_C128_Code->push_back(new element_t("15", "/", "/", "15", "10111001100"));
	m_C128_Code->push_back(new element_t("16", "0", "0", "16", "10011101100"));	
	m_C128_Code->push_back(new element_t("17", "1", "1", "17", "10011100110"));
	m_C128_Code->push_back(new element_t("18", "2", "2", "18", "11001110010"));
	m_C128_Code->push_back(new element_t("19", "3", "3", "19", "11001011100"));
	m_C128_Code->push_back(new element_t("20", "4", "4", "20", "11001001110"));
	m_C128_Code->push_back(new element_t("21", "5", "5", "21", "11011100100"));
	m_C128_Code->push_back(new element_t("22", "6", "6", "22", "11001110100"));
	m_C128_Code->push_back(new element_t("23", "7", "7", "23", "11101101110"));
	m_C128_Code->push_back(new element_t("24", "8", "8", "24", "11101001100"));
	m_C128_Code->push_back(new element_t("25", "9", "9", "25", "11100101100"));
	m_C128_Code->push_back(new element_t("26", ":", ":", "26", "11100100110"));
	m_C128_Code->push_back(new element_t("27", ";", ";", "27", "11101100100"));
	m_C128_Code->push_back(new element_t("28", "<", "<", "28", "11100110100"));
	m_C128_Code->push_back(new element_t("29", "=", "=", "29", "11100110010"));
	m_C128_Code->push_back(new element_t("30", ">", ">", "30", "11011011000"));
	m_C128_Code->push_back(new element_t("31", "?", "?", "31", "11011000110"));
	m_C128_Code->push_back(new element_t("32", "@", "@", "32", "11000110110"));
	m_C128_Code->push_back(new element_t("33", "A", "A", "33", "10100011000"));
	m_C128_Code->push_back(new element_t("34", "B", "B", "34", "10001011000"));
	m_C128_Code->push_back(new element_t("35", "C", "C", "35", "10001000110"));
	m_C128_Code->push_back(new element_t("36", "D", "D", "36", "10110001000"));
	m_C128_Code->push_back(new element_t("37", "E", "E", "37", "10001101000"));
	m_C128_Code->push_back(new element_t("38", "F", "F", "38", "10001100010"));
	m_C128_Code->push_back(new element_t("39", "G", "G", "39", "11010001000"));
	m_C128_Code->push_back(new element_t("40", "H", "H", "40", "11000101000"));
	m_C128_Code->push_back(new element_t("41", "I", "I", "41", "11000100010"));
	m_C128_Code->push_back(new element_t("42", "J", "J", "42", "10110111000"));
	m_C128_Code->push_back(new element_t("43", "K", "K", "43", "10110001110"));
	m_C128_Code->push_back(new element_t("44", "L", "L", "44", "10001101110"));
	m_C128_Code->push_back(new element_t("45", "M", "M", "45", "10111011000"));
	m_C128_Code->push_back(new element_t("46", "N", "N", "46", "10111000110"));
	m_C128_Code->push_back(new element_t("47", "O", "O", "47", "10001110110"));
	m_C128_Code->push_back(new element_t("48", "P", "P", "48", "11101110110"));
	m_C128_Code->push_back(new element_t("49", "Q", "Q", "49", "11010001110"));
	m_C128_Code->push_back(new element_t("50", "R", "R", "50", "11000101110"));
	m_C128_Code->push_back(new element_t("51", "S", "S", "51", "11011101000"));
	m_C128_Code->push_back(new element_t("52", "T", "T", "52", "11011100010"));
	m_C128_Code->push_back(new element_t("53", "U", "U", "53", "11011101110"));
	m_C128_Code->push_back(new element_t("54", "V", "V", "54", "11101011000"));
	m_C128_Code->push_back(new element_t("55", "W", "W", "55", "11101000110"));
	m_C128_Code->push_back(new element_t("56", "X", "X", "56", "11100010110"));
	m_C128_Code->push_back(new element_t("57", "Y", "Y", "57", "11101101000"));
	m_C128_Code->push_back(new element_t("58", "Z", "Z", "58", "11101100010"));
	m_C128_Code->push_back(new element_t("59", "[", "[", "59", "11100011010"));
	m_C128_Code->push_back(new element_t("60", "\\", "\\", "60", "11101111010"));
	m_C128_Code->push_back(new element_t("61", "]", "]", "61", "11001000010"));
	m_C128_Code->push_back(new element_t("62", "^", "^", "62", "11110001010"));
	m_C128_Code->push_back(new element_t("63", "_", "_", "63", "10100110000"));
	m_C128_Code->push_back(new element_t("64", NUL, "`", "64", "10100001100"));
	m_C128_Code->push_back(new element_t("65", SOH, "a", "65", "10010110000"));
	m_C128_Code->push_back(new element_t("66", STX, "b", "66", "10010000110"));
	m_C128_Code->push_back(new element_t("67", ETX, "c", "67", "10000101100"));
	m_C128_Code->push_back(new element_t("68", EOT, "d", "68", "10000100110"));
	m_C128_Code->push_back(new element_t("69", ENQ, "e", "69", "10110010000"));
	m_C128_Code->push_back(new element_t("70", ACK, "f", "70", "10110000100"));
	m_C128_Code->push_back(new element_t("71", BEL, "g", "71", "10011010000"));
	m_C128_Code->push_back(new element_t("72", BS, "h", "72", "10011000010"));
	m_C128_Code->push_back(new element_t("73", TAB, "i", "73", "10000110100"));
	m_C128_Code->push_back(new element_t("74", LF, "j", "74", "10000110010"));
	m_C128_Code->push_back(new element_t("75", VT, "k", "75", "11000010010"));
	m_C128_Code->push_back(new element_t("76", FF, "l", "76", "11001010000"));
	m_C128_Code->push_back(new element_t("77", CR, "m", "77", "11110111010"));
	m_C128_Code->push_back(new element_t("78", SO, "n", "78", "11000010100"));
	m_C128_Code->push_back(new element_t("79", SI, "o", "79", "10001111010"));
	m_C128_Code->push_back(new element_t("80", DLE, "p", "80", "10100111100"));
	m_C128_Code->push_back(new element_t("81", DC1, "q", "81", "10010111100"));
	m_C128_Code->push_back(new element_t("82", DC2, "r", "82", "10010011110"));
	m_C128_Code->push_back(new element_t("83", DC3, "s", "83", "10111100100"));
	m_C128_Code->push_back(new element_t("84", DC4, "t", "84", "10011110100"));
	m_C128_Code->push_back(new element_t("85", NAK, "u", "85", "10011110010"));
	m_C128_Code->push_back(new element_t("86", SYN, "v", "86", "11110100100"));
	m_C128_Code->push_back(new element_t("87", ETB, "w", "87", "11110010100"));
	m_C128_Code->push_back(new element_t("88", CAN, "x", "88", "11110010010"));
	m_C128_Code->push_back(new element_t("89", EM, "y", "89", "11011011110"));
	m_C128_Code->push_back(new element_t("90", SUB, "z", "90", "11011110110"));
	m_C128_Code->push_back(new element_t("91", ESC, "{", "91", "11110110110"));
	m_C128_Code->push_back(new element_t("92", FS, "|", "92", "10101111000"));
	m_C128_Code->push_back(new element_t("93", GS, "}", "93", "10100011110"));
	m_C128_Code->push_back(new element_t("94", RS, "~", "94", "10001011110"));
	m_C128_Code->push_back(new element_t("95", US, DEL, "95", "10111101000"));
	m_C128_Code->push_back(new element_t("96", FNC3, FNC3, "96", "10111100010"));
	m_C128_Code->push_back(new element_t("97", FNC2, FNC2, "97", "11110101000"));
	m_C128_Code->push_back(new element_t("98", SHIFT, SHIFT, "98", "11110100010"));
	m_C128_Code->push_back(new element_t("99", CODE_C, CODE_C, "99", "10111011110"));
	m_C128_Code->push_back(new element_t("100", CODE_B, FNC4, CODE_B, "10111101110"));
	m_C128_Code->push_back(new element_t("101", FNC4, CODE_A, CODE_A, "11101011110"));
	m_C128_Code->push_back(new element_t("102", FNC1, FNC1, FNC1, "11110101110"));
	m_C128_Code->push_back(new element_t("103", START_A, START_A, START_A, "11010000100"));
	m_C128_Code->push_back(new element_t("104", START_B, START_B, START_B, "11010010000"));
	m_C128_Code->push_back(new element_t("105", START_C, START_C, START_C, "11010011100"));
	m_C128_Code->push_back(new element_t("", STOP, STOP, STOP, "11000111010"));

	m_startAElement = element_t("103", START_A, START_A, START_A, "11010000100");
	m_startBElement = element_t("104", START_B, START_B, START_B, "11010010000");
	m_startCElement = element_t("105", START_C, START_C, START_C, "11010011100");
	m_codeAElement = element_t("101", FNC4, CODE_A, CODE_A, "11101011110");
	m_codeBElement = element_t("100", CODE_B, FNC4, CODE_B, "10111101110");
	m_codeCElement = element_t("99", CODE_C, CODE_C, "99", "10111011110");
	m_codeStop = element_t("", STOP, STOP, STOP, "11000111010");

}

//计算检验位
string CBarCode128::CalculateCheckDigit()
{
	string currentStartChar = m_FormattedData[0];

	unsigned int CheckSum = 0;
	string s;
	element_t row;

    for (unsigned int i = 0; i < m_FormattedData.size(); i++)
	{
        //获取需要查找字符
		s = m_FormattedData[i];

		int index = FindCharEncodingRow(COLUMN_A, s);
		if (index > -1)
		{
            //尝试在A列中找到值
			row = *m_C128_Code->at(index);
		}
		else
		{
			index = FindCharEncodingRow(COLUMN_B, s);
			if (index > -1)
			{
                //尝试在B列中找到值
				row = *m_C128_Code->at(index);
			}
			else
			{
				index = FindCharEncodingRow(COLUMN_C, s);
				if (index > -1)
				{
					row = *m_C128_Code->at(index);
				}
				else
				{
					Error("To find the failure");
				}
			}
		}

		unsigned int value = atoi(row.Value.c_str());
		unsigned int addition = value * ((i == 0) ? 1 : i);
		CheckSum += addition;
	}//for

	unsigned int Remainder = (CheckSum % 103);
	char *strRem = new char[0];
	row = *m_C128_Code->at(Remainder);
	//row = m_C128_Code->at(FindCharEncodingRow(COLUMN_VALUE, IntToAlpha(Remainder, strRem, 10)));
	string encode = row.Encoding;

	/*
	if (row)
	{
		delete row;
	}	
	*/

	return encode;
}

void CBarCode128::BreakUpDataForEncoding()
{
	string temp = "";
	string tempRawdata = m_Raw_Data;

    //将原始数据分解为A和B编码值
	if (m_Type == A || m_Type == B)
	{
		for (unsigned int i = 0; i < m_Raw_Data.size(); i++)
		{			
			string data(1, m_Raw_Data.at(i));

			m_FormattedData.push_back(data);
		}
		return;
	}//if

	else if (m_Type == C)
	{
		if (!isNumber(m_Raw_Data))
		{
			Error("Only numeric values can be encoded with C128-C");
		}

		if (m_Raw_Data.size() % 2 > 0)
		{
			tempRawdata =  m_Raw_Data;
		}
	}//else if

	for (unsigned int i = 0; i < tempRawdata.size(); i++)
	{
		char c = tempRawdata[i];
		if (isdigit(c))
		{
			if (temp == "")
			{
				temp += c;
			}
			else
			{
				m_FormattedData.push_back(temp + c);
				temp = "";
			}
		}//if

		else
		{
			if (temp != "")
			{
				m_FormattedData.push_back(temp);
				temp = "";
			}
			string data(1, c);
			m_FormattedData.push_back(data);
		}//else
	}//for


	if (temp != "")
	{
		m_FormattedData.push_back(temp);
		temp = "";
	}//if
}

void CBarCode128::InsertStartandCodeCharacter()
{
 	string currentCodeString = "";
    vector<string>::iterator it;
	it = m_FormattedData.begin();

    if(m_Type != DYNAMIC)
    {
        switch(m_Type)
        {
        case A:
            m_FormattedData.insert(it,START_A);
            break;
        case B:
            m_FormattedData.insert(it,START_B);
            break;
        case C:
            m_FormattedData.insert(it,START_C);
            break;
        default:
            Error("EC128-4:Unknown start type in fixed type encoding");
            break;
        }
    }//if


    else
    {
        try
        {
			
            for(unsigned int i = 0;i < (m_FormattedData.size());i++)
            {
				vector<string>::iterator it;
				it = m_FormattedData.begin();
                int col = 0;
                vector<element_t> tempStartChars = FindStartorCodeCharacter(m_FormattedData[i],col);


                bool sameCodeSet = false;
                element_t row;
                for(unsigned int i = 0;i < tempStartChars.size();i++)
                {
                    row = tempStartChars[i];
                    if(row.A == currentCodeString || row.B == currentCodeString
                            ||row.C == currentCodeString)
                    {
                        sameCodeSet = true;
                        break;
                    }//if
                }//foreach

                if(currentCodeString == "" ||!sameCodeSet )
                {
                    element_t currentCodeSet = tempStartChars[0];

                    if(currentCodeSet.A == START_A ||currentCodeSet.B == START_A
                            || currentCodeSet.C == START_A)
                    {
                        currentCodeString = START_B;
						m_FormattedData.insert(it, currentCodeString);
                        break;
                    }
                    else if(currentCodeSet.A == START_B || currentCodeSet.B == START_B
                            || currentCodeSet.C == START_B)
                    {
                        currentCodeString = START_B;
						m_FormattedData.insert(it, currentCodeString);
                        break;
                    }
                    else if(currentCodeSet.A == START_C || currentCodeSet.B == START_C
                            || currentCodeSet.C == START_C)
                    {
                        currentCodeString = START_C;
						m_FormattedData.insert(it, currentCodeString);
                        break;
                    }
                    else
                    {
                        Error("No start character found in CurrentSet");
                    }
                    //m_FormattedData.insert(it++,currentCodeString);					
                }//if
            }//for
        }
        catch(const exception&e)
        {
            Error("EC128-3:Could not insert start and code character.\n Message : " + (string)e.what());
        }//catch
    }//else
}

vector<element_t> CBarCode128::FindStartorCodeCharacter(string s, int &col)
{
    vector<element_t> rows = vector<element_t>();

    if(s.size() > 1 && (isdigit(s[0]) || &s[0] ==FNC1) && (isdigit(s[1]) || &s[1] == FNC1))
    {
        if(!&m_StartCharacter)
        {
            m_StartCharacter = m_startCElement;
            rows.push_back(m_StartCharacter);
        }
        else
        {
            rows.push_back(m_startCElement);
        }

        col = 1;
    }//if

    else
    {
        bool AFound = false;
        bool BFound = false;
        for(unsigned int i = 0; i < m_C128_Code->size();i++)
        {
            element_t *row = m_C128_Code->at(i);
            try
            {
                if(!AFound && s == row->A)   //found A
                {
                    AFound = true;
                    col = 2;

                    if(!&m_StartCharacter)
                    {
                        m_StartCharacter = m_startAElement;
                        rows.insert(rows.begin(),m_StartCharacter);
						//m_StartCharacter = m_codeAElement;
						//rows.insert(rows.begin(), m_codeAElement);
                    }
                    else
                    {
                        rows.insert(rows.begin(),m_startAElement);
					//	rows.insert(rows.begin(), m_codeAElement);
                    }
                }//if
                else if(!BFound && s == row->B)    //found B
                {
                    BFound = true;
                    col = 1;

                    if(!&m_StartCharacter)
                    {
                        m_StartCharacter = m_startBElement;
                        rows.insert(rows.begin(),m_StartCharacter);
						//m_StartCharacter = m_codeBElement;
						//rows.insert(rows.begin(), m_StartCharacter);
                    }
                    else
                    {
                        rows.insert(rows.begin(),m_startBElement);
						//rows.insert(rows.begin(), m_codeBElement);
                    }
                }
                else if(AFound && BFound)
                {
                    break;
                }
            }//try

            catch(const exception &e)
            {
                Error("EC128-1: " + (string)e.what());
            }
        }//foreach
        if(rows.size() <= 0)
        {
            Error("EC128-2: Could not determine start character");
        }
    }
    return rows;
}


//获取编码
string CBarCode128::GetEncoding()
{
    m_FormattedData.clear();

    //分解数据进行编码
    BreakUpDataForEncoding();

    //插入起始字符
    InsertStartandCodeCharacter();

	//当编码类型为DYNAMIC时，增加编码转换符
	if (m_Type == DYNAMIC)
	{
		InsertAutoControlCode();
	}

	//计算校验位，并获取校验的编码
	string CheckDigit = CalculateCheckDigit();

    m_Encoded_Data = "";

    for(unsigned int i = 0; i < m_FormattedData.size();i++)
    {
        string s = m_FormattedData[i];

        element_t *E_Row = nullptr;

        switch(m_Type)
        {
        int ind;
        case A:
            ind = FindCharEncodingRow(COLUMN_A,s);
            if(ind >= 0)
            {
                E_Row = m_C128_Code->at(ind);
            }
            break;
        case B:
            ind = FindCharEncodingRow(COLUMN_B,s);
            if(ind >= 0)
            {
                E_Row = m_C128_Code->at(ind);
            }
            break;
        case C:
            ind = FindCharEncodingRow(COLUMN_C,s);
            if(ind >= 0)
            {
                E_Row = m_C128_Code->at(ind);
            }
            break;
        case DYNAMIC:
			if (m_FormattedData[0] == START_B || m_FormattedData[0] == START_A)
			{
				ind = FindCharEncodingRow(COLUMN_B, s);
				if (ind < 0)
				{										
						ind = FindCharEncodingRow(COLUMN_C, s);					
				}
			}
			else if (m_FormattedData[0] == START_C)
			{
				ind = FindCharEncodingRow(COLUMN_C, s);
				if (ind < 0)
				{					
					ind = FindCharEncodingRow(COLUMN_B, s);				
				}
			}

            if(ind >= 0)
            {
                E_Row = m_C128_Code->at(ind);
            }
            break;
        default:
            break;
        }//switch

        if(E_Row == nullptr)
        {
            Error("EC128-5:Could not find encoding of a value(" ") in C128");
            return "";
        }
        m_Encoded_Data += E_Row->Encoding;
    }//for

    //编码数据 + 检验位
    m_Encoded_Data += CheckDigit;

    //编码数据 + 停止位
    m_Encoded_Data += m_codeStop.Encoding;	

    m_Encoded_Data += "11";

    return m_Encoded_Data;
}

void CBarCode128::Error(string msg)
{
    cout<<msg<<endl;
}

//查找字符编码
int CBarCode128::FindCharEncodingRow(COLUMN codeType, string value)
{
    for(unsigned int i = 0; i < m_C128_Code->size() - 1;i++)
    {
        switch(codeType)
        {
        case COLUMN_A:
            if(m_C128_Code->at(i)->A == value)
            {
                return i;
            }
            break;
        case COLUMN_B:
            if(m_C128_Code->at(i)->B == value)
            {
                return i;
            }
            break;
        case COLUMN_C:
            if(m_C128_Code->at(i)->C == value)
            {
                return i;
            }
            break;
        case COLUMN_VALUE:
            if(m_C128_Code->at(i)->Value == value)
            {
                return i;
            }
            break;
        default:
            break;
        };
    }
    return -1;
}

char* CBarCode128::IntToAlpha(int value, char *result, int base)
{
    //检查基数是否有效
    if(base < 2 || base >36)
    {
        *result = '\0';
        return result;
    }

    char *ptr = result,*ptr_1 = result,tem_char;
    int temp_value;

    do
    {
        temp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"
                [35 + (temp_value - value * base)];
    }while(value);

    //应用负号
    if(temp_value < 0)
    {
        *ptr++ = '-';
    }

    *ptr-- = '\0';
    while(ptr_1 < ptr)
    {
        tem_char = *ptr;
        *ptr-- = *ptr_1;
        *ptr_1++ = tem_char;
    }
    return result;
}

//判断 s 中字符是否为数字
bool CBarCode128::isNumber(const string &s)
{
    return !s.empty() && s.find_first_not_of("-.0123456789") == string::npos;
}

//获取文本内容
string CBarCode128::GetText()const
{
	return m_Raw_Data;
}

//设置文本内容
void CBarCode128::SetText(string text)
{
	m_Raw_Data = text;
	m_CodeInfo.sText = text;
}

string CBarCode128::SetReverse(string encode)
{
	if (encode.empty())
	{
		return "";
	}

	m_CodeInfo.bReverse = true;
	string reversestr;
    for (unsigned int i = encode.length(); i >= 0; i--)
	{
		reversestr += encode[i];
	}
	return reversestr;
}


void CBarCode128::InsertAutoControlCode()
{
	unsigned int iCount = m_FormattedData.size();
	// 只有当 ind > 0 && bFound* == true 才进行插入类型转换码
	bool bFoundA = true;
	bool bFoundB = true;
	bool bFoundC = true;
	int j = 0;
	for (int i = 0; i < iCount; i++)
	{
		int ind;
		string s = m_FormattedData[i];		
		
		//当起始编码为B类型时，在B子集下切换编码, 由于A 和 B编码大部分相同，所以不在 A 子集中查找插入
		if (m_FormattedData[0] == START_B || m_FormattedData[0] == START_A)  
		{
			ind = FindCharEncodingRow(COLUMN_B, s);
			if (ind < 0)
			{
				ind = FindCharEncodingRow(COLUMN_C, s);
				if (ind >= 0 && bFoundC)
				{
					//插入编码转换符
					m_FormattedData.insert(m_FormattedData.begin() + i, CODE_C);
					iCount++;
					bFoundC = false;
					bFoundB = false;
				}
			}
			else if(ind >= 0 && !bFoundB)
			{
				m_FormattedData.insert(m_FormattedData.begin() + i, CODE_B);
				iCount++;
				bFoundC = true;
				bFoundB = true;
			}
		} // m_FormatedData[0] == start_b

		// 当起始编码为C类型时，在C子集中切换编码，A | B 大部分相同所以只在 B 子集中查找 
		else if (m_FormattedData[0] == START_C)
		{
			ind = FindCharEncodingRow(COLUMN_C, s);
			if (ind < 0)
			{
				ind = FindCharEncodingRow(COLUMN_B, s);
				if (ind >= 0 && bFoundB )
				{
					//插入编码转换符
					m_FormattedData.insert(m_FormattedData.begin() + (i ), CODE_B);
					j++;
					iCount++;
					bFoundB = false;
					bFoundC = false;
				}				
			}
			else if(ind >= 0 && !bFoundC)
			{
				m_FormattedData.insert(m_FormattedData.begin() + i, CODE_C);
				iCount++;
				bFoundB = true;
				bFoundC = true;
			}
		}
		j++;
	}
}
