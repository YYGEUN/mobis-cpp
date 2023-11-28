#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base(){} // 기반 클래스로 설계되는 클래스는 반드시 가상소멸자 지정
};

class Derived
	:public Base
{
public:
	Derived() { cout << "메모리할당\n"; };
	~Derived() { cout << "메모리해지\n"; };

};

int main()
{
	Derived d;
	Derived* pd = new Derived;
					//1. 힙에 메모리 할당
					//2. 생성자 호출

	delete pd;
					//1. 소멸자 호출
					//2. 메모리 해지

	Base* bpd = new Derived;

	delete bpd;
					// 소멸자를 호출해야하는데 소멸자 호출도 함수호출이다.
					// static binding, dynamic binding 결정해야함
					// 1. 컴파일러는 p가 Base* 라는 것만 알고 있음
					// 2. 그래서 Base선언에서 소멸자가 가상함수인지 조사
					//		--> 아니면 컴파일러가 제공 (가상함수가 아닌 소멸자)

					// 가상이아니면 delete bpd 할때 Base 소멸자만 호출
					// 가상이면     delete bpd 할때 실제bpd가 가리키는 객체를 조사후 소멸자 호출

	return 0;
}