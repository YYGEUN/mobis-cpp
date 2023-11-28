#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

class CString
{
private:
	char* m_str;
	int m_length;
public:
	CString()
	{
		cout << "const call" << endl;
		this->m_str = 0;
		this->m_length = 0;
	}

	CString(const char* str)
	{
		cout << "arg const call" << endl;
		this->m_length = strlen(str)+1;
		this->m_str = new char[m_length];
		strcpy_s(this->m_str, this->m_length, str);
	}

	CString(const CString& string)
	{
		cout << "copy const call" << endl;
		this->m_length = strlen(string.m_str) + 1;
		this->m_str = new char[m_length];
		strcpy_s(this->m_str, this->m_length, string.m_str);
	}

	~CString()
	{
		cout << "dest call" << endl;
		delete m_str;
	}

	CString& operator=(CString& string)
	{
		cout << "op call" << endl;
		if (this->m_str != 0)
		{
			delete m_str;
		}
		this->m_length = string.m_length;
		this->m_str = new char[m_length];
		strcpy_s(this->m_str, this->m_length, string.m_str);
		return *this;
	}
	CString& operator=(const char* str)
	{
		cout << "op arg call" << endl;
		if (this->m_str != 0)
		{
			delete m_str;
		}
		this->m_length = strlen(str)+1;
		this->m_str = new char[m_length];
		strcpy_s(this->m_str, this->m_length, str);
		return *this;
	}

	void Print()
	{
		cout << m_str << endl;
	}

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CString str1("abcdefg");
	CString str2 = "abcdefg";
	str1.Print();
	str2.Print();

	str1 = "korea";
	str2 = str1;
	CString str3 = str1;
	str1.Print();
	str2.Print();
	str3.Print();

	return 0;
}