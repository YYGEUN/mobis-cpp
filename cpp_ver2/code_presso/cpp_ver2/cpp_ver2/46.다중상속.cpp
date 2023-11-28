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

class C :public A, public B { // C ���忡�� BASE�� A,B�κ��� �޾��� --> ���̾Ƹ�� ��ӹ���
public:
	void CFn() { cout << "cfn" << endl; }
};

int main()
{
	C cobj;
	cobj.AFn();
	cobj.BFn();
	cobj.CFn();
	//cobj.baseFn(); // A���� �°��� , B���� �°��� ��
	cobj.baseFn(); // --> virtual ���ó�����༭ �ذ��ؾ���, ���߻���� �ִ��� ���Ұ�

	return 0;
}
