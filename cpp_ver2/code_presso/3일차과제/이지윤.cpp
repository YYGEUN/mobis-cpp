#include <iostream>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

using namespace std;
class CString{
private:
	char* m_str;
	int m_length;

public:
	CString();
	CString(const char* str) {
		m_length = strlen(str) + 1;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, str);
	}
	CString(const CString& string) {
		m_length = string.m_length;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, string.m_str);
	}
	~CString() {
		delete[] m_str;
	}

	CString& operator=(CString& string) {
		delete[] m_str;
		m_length = string.m_length;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, string.m_str);
		
		return *this;
	}
	CString& operator=(const char* str) {
		delete[] m_str;
		m_length = strlen(str) + 1;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, str);
		
		return *this;
	}

	void Print() {
		for (int i = 0; i < m_length - 1; i++) {
			printf("%c", m_str[i]);
		}
		printf("\n");
	}

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CString str1("abcdefg");
	CString str2 = "abcdefg";
	str1.Print();
	str2.Print();

	str1 = "kor";
	str2 = str1;
	CString str3 = str1;
	str1.Print();
	str2.Print();
	str3.Print();

	return 0;
}