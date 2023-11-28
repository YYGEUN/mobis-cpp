#include <iostream>
#include <typeinfo>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
using namespace std;

class CString
{
private:
	char* m_str;
	int m_length;
public:
	CString() {
		m_str = nullptr;
		m_length = 0;
	}
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
	CString operator=(CString& string) {
		delete[] m_str;
		m_length = string.m_length;
		m_str = new char[m_length];
		strcpy_s(m_str, m_length, string.m_str);

		return *this;
	}
	CString operator=(const char* str) {
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

	~CString() {
		delete[] m_str;
	}
	int GetLength() {
		return m_length;
	}
	//char GetAt(int position);

	CString& operator+(CString& string) {
		int tmplen = string.m_length + m_length;
		char* m_tmp = new char[tmplen + 1];
		sprintf_s(m_tmp, m_length, m_str);
		//strcpy_s(m_tmp, m_length + 1, m_str);
		strcat_s(m_tmp, tmplen + 1, string.m_str);
		delete[] m_str;
		m_length = tmplen;
		m_str = m_tmp;

		return *this;
	}
	CString& operator+(const char* str) {

		int tmplen = strlen(str) + m_length;
		char* m_tmp = new char[tmplen + 1];
		strcpy_s(m_tmp, m_length + 1, m_str);
		strcat_s(m_tmp, tmplen + 1, str);
		delete[] m_str;
		m_length = tmplen;
		m_str = m_tmp;

		return *this;
	}
	CString operator+=(CString& string) {
		int tmplen = string.m_length + m_length;
		char* m_tmp = new char[tmplen + 1];
		strcpy_s(m_tmp, m_length + 1, m_str);
		strcat_s(m_tmp, tmplen + 1, string.m_str);
		delete[] m_str;
		m_length = tmplen;
		m_str = m_tmp;

		return *this;
	}
	CString operator+=(const char* str) {

		int tmplen = strlen(str) + m_length;
		char * m_tmp = new char[tmplen +1];
		strcpy_s(m_tmp, m_length + 1, m_str);
		strcat_s(m_tmp, tmplen + 1, str);
		delete[] m_str;
		m_length = tmplen;
		m_str = m_tmp;

		return *this;
	}

	bool operator!=(CString& string) {
		if (m_length != string.m_length) {
			return 1;
		}

		for (size_t i = 0; i < m_length-1; i++)
		{
			if (m_str[i] != string.m_str[i]) {
				return 1;
			}
		}

		return 0;
	}
	bool operator!=(const char* str) {
		if (m_length-1 != strlen(str)) {
			return 1;
		}
		for (size_t i = 0; i < m_length-1; i++)
		{
			if (m_str[i] != str[i]) {
				return 1;
			}
		}
		return 0;
	}
	bool operator==(CString& string) {
		if (m_length != string.m_length) {
			return 0;
		}
		for (size_t i = 0; i < m_length-1; i++)
		{
			if (m_str[i] != string.m_str[i]) {
				return 0;
			}
		}
		return 1;
	}
	bool operator==(const char* str) {

		if (m_length-1 != strlen(str)) {
			return 0;
		}
		for (size_t i = 0; i < m_length-1; i++)
		{
			if (m_str[i] != str[i]) {
				return 0;
			}
		}
		return 1;
	}
	friend ostream& operator<<(ostream& o, CString& r) {
		cout << r.m_str;
		return o;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CString str1("abcdefg");
	CString str2 = "abcdefg";
	str1 = "abcdefg";
	str2 = str1;
	CString str3 = str1;

	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	cout << "str3=" << str3 << endl;

	cout << str1.GetLength() << endl;

	str1 = "ag";
	cout << "str1= ag :" << str1 << endl;
	str1 += str2;  //문자열연결( strcat, sprintf)
	cout << "str1 += str2 :" << str1 << endl;
	str1 += "et";  //문자열연결( strcat, sprintf)
	cout << "str1 + et :" << str1 << endl;
	

	str1 = str2 + str3;  //문자열연결( strcat, sprintf)
	cout << "str1 = str2 + str3 : " << str1 << endl;
	str1 = str2 + "rh";  //문자열연결( strcat, sprintf)
	cout << "str2 + rh : " << str1 << endl;


	CString str4("tbcdefg");
	cout << str1.GetLength() << endl; //문자갯수
	//cout << str1.GetAt(2) << endl; //2번째문자 

	CString str5("abc");
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;
	cout << "str3=" << str3 << endl;
	cout << "str4=" << str4 << endl;

	if (str5 == "abc")
		cout << "두개의 문자가 같음" << endl;
	else
		cout << "두개의 문자가 틀림" << endl;

	if (str1 == str2)
		cout << "두개의 문자가 같음" << endl;
	else
		cout << "두개의 문자가 틀림" << endl;

	if (str1 != str4)
		cout << "두개의 문자가 틀림" << endl;
	else
		cout << "두개의 문자가 같음" << endl;

	if (str1 == "abc")
		cout << "두개의 문자가 같음" << endl;
	else
		cout << "두개의 문자가 틀림" << endl;

	if (str1 != "abc")
		cout << "두개의 문자가 틀림" << endl;
	else
		cout << "두개의 문자가 같음" << endl;

	return 0;
}