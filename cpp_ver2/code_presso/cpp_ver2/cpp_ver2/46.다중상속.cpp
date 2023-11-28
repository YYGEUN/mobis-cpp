#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
	void baseFn() { cout << "base" << endl; }
};

class A : virtual public Base{
public:
	void AFn() { cout << "afn" << endl; }
};

class B : virtual public Base{
public:
	void BFn() { cout << "bfn" << endl; }
};

class C :public A, public B { // C 입장에서 BASE가 A,B로부터 받아짐 --> 다이아몬드 상속문제
public:
	void CFn() { cout << "cfn" << endl; }
};

int main()
{
	C cobj;
	cobj.AFn();
	cobj.BFn();
	cobj.CFn();
	//cobj.baseFn(); // A에서 온건지 , B에서 온건지 모름
	cobj.baseFn(); // --> virtual 상속처리해줘서 해결해야함, 다중상속은 최대한 피할것

	return 0;
}
