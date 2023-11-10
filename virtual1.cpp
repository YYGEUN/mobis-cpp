#include <iostream>
class Animal
{
public:
	// non-virtual : 기본 바인딩(static binding) 해달라는 의미
	void cry1() { std::cout << "Animal cry1\n"; }

	// virtual : dynamic binding 해달라는 의미
	virtual void cry2() { std::cout << "Animal cry2\n"; }
};

class Dog : public Animal 
{
public:
	// override!
	void cry1() { std::cout << "Dog cry1\n"; }
	void cry2() override { std::cout << "Dog cry2\n"; }
};

int main()
{
	Animal a; a.cry1(); // Animal cry1
	Dog    d; d.cry1(); // Dog cry1

	Animal* p = &d;

//	if( 사용자가 실행시간에 입력한값 == 1 ) p = &a;

	p->cry1();
}

// p->cry1() 의 코드를 어떤 함수와 연결 할것인가 ??
// => 함수 바인딩(binding) 이라고 합니다

// 1. static binding : 컴파일 시간에 컴파일러가 함수 호출을 결정하는 것
// 						컴파일러는 p 가 가리키는 객체가 어느 객체인지는 알수 없다.
//						단지, p 자체의 타입이 Animal 이라는 것만 알수 있다.
//						그래서, 컴파일러가 결정하는 "Animal cry1" 호출
// 논리적이지 않다. 빠르다
// C++, C# 의 기본 바인딩.!!

// 2. dynamic binding : 컴파일 할때는 p가 가리키는 메모리를 조사하는 기계어 코드를 생성
//						실행할때 p 가 가리키는 메모리를 조사후 함수를 결정
//						p가 Dog 를 가리켰다면 "Dog cry1" 호출
// 논리적이다. 느리다.
// java, objective-c, kotlin, python 등의 언어는 이방식으로 동작!!!
// C++, C# 의 virtual function!








