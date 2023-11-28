#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


using namespace std;

class Test {
private:
    int a;
    int b;
};

class CString {
private:
    char* m_str;
    int m_length;

public:
    CString() {
        cout << "Default constructor call" << endl;
        delete[] m_str;
        m_length = 0;
        m_str = nullptr;
    }

    CString(const char* str) {
        cout << "one argue constructor call" << endl;
        delete[] m_str;
        m_length = strlen(str) + 1;
        m_str = new char[m_length];
        strcpy_s(m_str, m_length, str);
    }

    CString(const CString& string) {
        cout << "Copy constructor call" << endl;
        delete[] m_str;
        m_length = string.m_length;
        m_str = new char[m_length];
        strcpy_s(m_str, m_length, string.m_str);
    }

    ~CString() {
        cout << "Destructor call" << endl;
        delete[] m_str;
    }

    CString& operator=(const CString& string) {
        cout << "Copy operator call" << endl;
        delete[] m_str;
        m_length = string.m_length;
        m_str = new char[m_length];
        strcpy_s(m_str, m_length, string.m_str);
        return *this;
    }

    CString& operator=(const char* str) {
        cout << "Operator call" << endl;
        delete[] m_str;
        m_length = strlen(str) + 1;
        m_str = new char[m_length];
        strcpy_s(m_str, m_length, str);
        return *this;
    }

    void Print() {
        if (m_str) {
            cout << m_str << endl;
        }
    }
};

void fn()
{
    Test* p = new Test;
    delete p;

}

int main() {
    CString str1("abcdefg");
    CString str2 = "abcdefg"; //Csting str2 = Cstring("abcvds")

    str1.Print();
    str2.Print();

    str1 = "korea";
    str2 = str1;
    CString str3 = str1;

    str1.Print();
    str2.Print();
    str3.Print();

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    fn();
    fn();

    return 0;
}