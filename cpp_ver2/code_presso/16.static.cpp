#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

class Test {
private:
	int a; //�ν��Ͻ�����
	int b;
public:
	static int st; //static����
	void setData(int x, int y) {
		a = x;
		b = y;
	}
	void show() //show( Test* this)  //�ν��Ͻ��Լ� ��ü.show( &��ü)
	{
		cout << "a=" << a << " b=" << b << endl;
		//st = 10; //Test::st = 10;
	}
	// this ���� �ν��Ͻ� ���� ���X
	static void stFn(int x) 
	{
		//cout << this << endl;
		//this->a = x;
		st = x; // Test::st =x 
	}
};
int Test::st = 100;

class MyClass {
private:
	static int nCnt;
public:
	MyClass() {
		nCnt++; //MyClass::nCnt++
		cout << "call" << endl;
	}
	static int GetCnt() {
		return nCnt; //MyClass::nCnt
	}
};
int MyClass::nCnt = 0;

int main() {
	MyClass tt1;
	MyClass tt2;
	MyClass tt3;
	cout << MyClass::GetCnt() << endl;

	//��ü.stFn( &��ü,10)
	//Test::stFn(100);
	//Test::st = 20;
	//cout << Test::st << endl;

	/*MyClass tt1;
	MyClass tt2;
	MyClass tt3;*/
	// ������ ��ü�� ���� 3



	return 0;
}

