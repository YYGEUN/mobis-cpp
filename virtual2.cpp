// virtual2.cpp
#include <iostream>

class Base
{
public:
	virtual ~Base() {} // 핵심 : 기반 클래스로 설계되는 클래스는 반드시
						//      소멸자를 가상함수로 설계 해야 한다. (흔히, 가상소멸자라고 합니다)
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "메모리(자원)할당\n";}
	~Derived() { std::cout << "메모리(자원)해지\n";}
};
int main()
{
//	Derived d; // ok

//	Derived* p = new Derived;
					// 1. 힙에 메모리 할당
					// 2. 생성자 호출
//	delete p;	
			// 1. 소멸자 호출
			// 2. 메모리 해지

	Base* p = new Derived;

	delete p;
		// => 이순간 소멸자를 호출해야 하는데.. 소멸자 호출도 결국, 함수 호출입니다.
		// => static binding 할지 dynamic binding 할지 결정해야 합니다

		// 1. 컴파일러는 p가 Base* 라는 것만 알고 있습니다.
		// 2. 그래서 Base 선언에서 소멸자가 가상함수 인지 아닌지를 조사합니다.
		//    => 사용자가 만들지 않으면 컴파일러가 제공하는데, "가상함수가 아닌 소멸자" 입니다.

		// Base 소멸자가 virtual 이 아니면 : delete p 하는 순간 Base 소멸자만 호출됨
		// Base 소멸자가 virtual 이면     : delete p 하는 순간 실제 p가 가리키는 객체를 조사후
		//									해당 타입의 소멸자 호출.
}












