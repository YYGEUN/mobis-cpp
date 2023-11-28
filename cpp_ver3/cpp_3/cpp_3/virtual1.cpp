#include <iostream>
using namespace std;

class Animal
{
public:
	void cry1() { cout << "Animal cry" << endl; }
	virtual void cry2() { cout << "Animal cry" << endl; }
};

class Dog
	:public Animal
{
public:
	// override
	void cry1() { cout << "Dog cry" << endl; }
	virtual void cry2() override { cout << "Dog cry" << endl; }
	// override 가있으면 체크 해줌 (기반클래스의 가상함수를 제대로 받는지)
	// virtual은 빼도되고 넣어도됨
};

int main()
{
	Animal a;
	a.cry1();
	Dog d;
	d.cry1();

	Animal* p = &d;
	
	// if(사용자가입력한값 == 1) p=&a;

	p->cry1();
	p->cry2();

	// p->cry1() 은 어떤함수와 연결될까
	// 함수 바인딩 (binding)

	// static = 컴파일시 , dynamic = 실행시
	// 1.static binding;
	// --> 컴파일러가 컴파일시간에 함수 호출을 결정
	// --> 컴파일러는 p가 가리키는 객체가 어느객체인지 모름 단지 p타입은 Animal
	// --> 따라서 컴파일러가 결정하는 Animal cry1 호출
	// ------------> 논리적이진않음, 실행속도 빠름
	// c++, c#
	// 
	// 2.dynamic binding;
	// --> 컴파일시 p가 가리키는 메모리를 조사하는 기계어 코드 생성
	// --> 실행할떄 p 가 가리키는 메모리를 조사후 함수 결정
	// --> 위에선 p가 Dog를 가리키므로 Dog cry1 호출
	// ------------> 논리적 , 실행속도 느림
	// java, objective-c, kotlin, python

	// c++ 은 위 binding을 선택할수있다(virtual function) 개발자직접 default는 static인듯
}