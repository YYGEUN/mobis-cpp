#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;
class CString
{
private:
	char* m_str;
	int m_length;
public:
	CString() {
		this->m_str = 0;
		this->m_length = 0;
	};
	CString(const char* str) {
		m_length = strlen(str);
		this->m_str = new char[m_length+1];
		strcpy_s(this->m_str, m_length + 1, str);
	};
	CString(const CString& string) {
		m_length = string.m_length;
		this->m_str = new char[m_length + 1];
		strcpy_s(this->m_str, m_length + 1, string.m_str);

	};
	~CString() {
		delete[] m_str;
	};
	CString operator=(CString& string) {
		if (this == &string) {
			return *this;
		}
		m_length = string.m_length;
		delete[] m_str; // 기존 메모리를 해제
		this->m_str = new char[m_length + 1];
		strcpy_s(this->m_str, m_length + 1, string.m_str);
		return *this;
	};
	CString operator=(const char* str) {

		m_length = strlen(str);
		delete[] m_str; // 기존 메모리를 해제
		this->m_str = new char[m_length + 1];
		strcpy_s(this->m_str, m_length + 1, str);
		return *this;
	};
	void Print() {
		if (m_str != nullptr) {
			cout << m_str << endl;
		}
	};
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