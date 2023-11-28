#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;
class CString
{
private:
	char* m_str;
	int m_length;
public:
	CString() : m_str(0), m_length(0) { ; }
	CString(const char* str) {
		m_length = strlen(str);
		m_str = new char[m_length + 1];
		strcpy(m_str, str);
	}
	CString(const CString& string) {
		m_length = string.m_length;
		m_str = new char[m_length + 1];
		strcpy(m_str, string.m_str);
	}
	~CString() { delete[] m_str; }
	CString& operator=(const CString& string) {
		m_length = string.m_length;
		if (m_str != NULL) { delete[] m_str; }
		m_str = new char[m_length + 1];
		strcpy(m_str, string.m_str);
		return *this;
	}
	CString& operator=(const char* str) {
		m_length = strlen(str);
		if (m_str != NULL) { delete[] m_str; }
		m_str = new char[m_length + 1];
		strcpy(m_str, str);
		return *this;
	}
	CString operator+(const CString& str) {
		CString newStr;
		newStr.m_length = m_length + str.m_length;
		newStr.m_str = new char[newStr.m_length + 1];
		strcpy(newStr.m_str, m_str);
		for (int i = m_length; i <= newStr.m_length; i++) {
			newStr.m_str[i] = str.m_str[i - m_length];
		}
		return newStr;
	}
	CString operator+(const char* str) {
		CString newStr;
		newStr.m_length = m_length + strlen(str);
		newStr.m_str = new char[newStr.m_length + 1];
		strcpy(newStr.m_str, m_str);
		for (int i = m_length; i <= newStr.m_length; i++) {
			newStr.m_str[i] = str[i - m_length];
		}
		return newStr;
	}
	void Print() { cout << m_str << endl; }
	friend ostream& operator<<(ostream& os, const CString& str);
};

ostream& operator<<(ostream& os, const CString& str) {
	printf("%s", str.m_str);
	return os;
}

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
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	cout << str1 + str3 << endl;
	cout << str1 + "abcdefg" << endl;
	str1 = str1 + str3 + "abcdefg";
	cout << str1 << endl;

	return 0;
}