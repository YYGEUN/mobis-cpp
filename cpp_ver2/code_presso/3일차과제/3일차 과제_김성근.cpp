#include <iostream>
//#include <string>
using namespace std;
class CString
{
private:
	char* m_str;
	int m_length;

public:

	CString();
	CString(const char* str) {
		int n;
		n = strlen(str) + 1;
		m_str = new char[n];
		strcpy_s(this->m_str, n, str);
	}

	CString(const CString& string)
	{
		int n;
		n = strlen(string.m_str) + 1;
		m_str = new char[n];
		strcpy_s(this->m_str, n, string.m_str);
	}

	~CString()
	{
		cout << endl << "dest call" << endl;
		delete[] m_str;
	}
	CString& operator=(CString& string)
	{
		if (m_str != nullptr) {
			delete[] m_str;
			m_str = nullptr;
		}

		int n;
		n = strlen(string.m_str) + 1;
		m_str = new char[n];
		strcpy_s(this->m_str, n, string.m_str);
		return *this;
	}
	CString& operator=(const char* str)
	{
		if (m_str != nullptr) {
			delete[] m_str;
			m_str = nullptr;
		}

		int n;
		n = strlen(str) + 1;
		m_str = new char[n];
		strcpy_s(this->m_str, n, str);
		return *this;
	}
	void Print()
	{
		printf("Print함수 오버로딩 : %s\n", m_str);
	}
};


int main()
{
	// f5 디버기 실행시 메모리 누수 확인
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CString str1("abcdefg");
	CString str2 = "abcdefg";
	str1.Print();
	str2.Print();

	str1 = "abcdefgh";
	str2 = str1;
	CString str3 = str1;
	str1.Print();
	str2.Print();
	str3.Print();

	return 0;
}