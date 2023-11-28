#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class CString
{
public:
	char* m_str;
	int m_length;
public:
	CString() {
		cout << "construct" << endl;
		this->m_str = 0;
		this->m_length = 0;
	}
	CString(const char* str) {
		cout << "arg construct" << endl;
		this->m_length = strlen(str);
		this->m_str = new char[strlen(str) + 1];
		strcpy_s(this->m_str, this->m_length + 1, str);
	}
	CString(const CString& string) {
		cout << "class construct" << endl;
		this->m_length = string.m_length;
		this->m_str = new char[strlen(string.m_str) + 1];
		strcpy_s(this->m_str, this->m_length + 1, string.m_str);
	}
	
	~CString() {
		cout << "dest call" << endl;
		delete[] m_str;
	}
	CString& operator=(CString& string) {
		cout << "op class construct" << endl;
		delete[] this->m_str;
		this->m_length = string.m_length;
		this->m_str = new char[strlen(string.m_str) + 1];
		strcpy_s(this->m_str, this->m_length + 1, string.m_str);
		return *this;
	}
	CString& operator=(const char* str) {
		cout << "op str construct" << endl;

		delete[] this->m_str;
		this->m_length = strlen(str);
		this->m_str = new char[strlen(str) + 1];
		strcpy_s(this->m_str, this->m_length + 1, str);
		return *this;
	}
	void Print() {
		cout << "str : " << m_str << "(length : " << m_length << ")" << endl;
	}

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	CString str1("abcdefg");
	CString str2 = "abcdedddddddddddddddddddddddddddd";
	str1.Print();
	str2.Print();

	str1 = "KOREA";
	str2 = str1;
	CString str3 = str1;
	str1.Print();
	str2.Print();
	str3.Print();
	
	return 0;
}