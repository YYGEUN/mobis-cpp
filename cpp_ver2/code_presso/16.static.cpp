#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

class Test {
private:
	int a; //인스턴스변수
	int b;
public:
	static int st; //static변수
	void setData(int x, int y) {
		a = x;
		b = y;
	}
	void show() //show( Test* this)  //인스턴스함수 객체.show( &객체)
	{
		cout << "a=" << a << " b=" << b << endl;
		//st = 10; //Test::st = 10;
	}
	// this 인자 인스턴스 변수 사용X
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

	//객체.stFn( &객체,10)
	//Test::stFn(100);
	//Test::st = 20;
	//cout << Test::st << endl;

	/*MyClass tt1;
	MyClass tt2;
	MyClass tt3;*/
	// 생성된 객체의 수는 3



	return 0;
}

