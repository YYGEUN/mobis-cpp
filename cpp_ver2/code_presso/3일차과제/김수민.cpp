#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;

class CString {
private:
	char* m_str;
	int m_length;
public:
	CString() {
		this->m_str = 0;
		this->m_length = 0;
	}
	CString(const char* str) {
		cout << "const call" << endl;
		
		//기존에 있는 array를 날리는 코드가 들어가야해 (기존 문자열 지우고 새로운 문자열을 생성할거야)
		int n;
		n = strlen(str) + 1;
		this->m_length = n;
		this->m_str = new char[strlen(str) + 1];
		strcpy_s(this->m_str, n, str);
	}
	CString(const CString& string) {
		cout << "copy const call" << endl;
		int n;
		n = strlen(string.m_str) + 1;
		this->m_length = n;
		this->m_str = new char[n];
		strcpy_s(this->m_str, n, string.m_str);
	}
	~CString() {
		cout << "dest call" << endl;
		delete[] m_str;
	}
	CString& operator = (const CString& string) {
		if (this->m_str != 0) {
			delete[] this->m_str;
		}
		cout << "=copy op call" << endl;
		this->m_length = string.m_length;
		int n;
		n = strlen(string.m_str) + 1;
		this->m_str = new char[n];
		strcpy_s(this->m_str, n, string.m_str);
		return *this;
	}
	CString operator = (const char* str) {
		cout << "=op call" << endl;
		if (this->m_str != 0) {
			delete[] this->m_str;
		}
		int n;
		n = strlen(str) + 1;
		this->m_length = n;
		this->m_str = new char[n];
		strcpy_s(this->m_str, n, str);
		return this->m_str;
	}
	
	void Print() {
		cout << "m_str=" << this -> m_str << endl;
		cout << "m_length" << this->m_length << endl;
	}
};

int main() {
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