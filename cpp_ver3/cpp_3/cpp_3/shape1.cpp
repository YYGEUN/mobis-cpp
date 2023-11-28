#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
	virtual ~Animal(){} // 상속시 모든기반 클래스소멸자는 반드시 가상함수
						// 기반 클래스 --> 가상 소멸자 필수
};

class Dog
	:public Animal
{
public:
	int color;
};

int main()
{
	Dog dog;
	Dog* p1 = &dog;
	//int* p2 = &dog; // 전혀다른타입
	Animal* p3 = &dog; // upcasting

	// 핵심1. 파생 클래스 객체의 주소를 기반 클래스 포인터에 담을수있다 
	// upcasting

	// 핵심2. 기반 클래스 포인터로는 기반클래스 멤버만 접근가능
	//		ex) 컴파일러 입장에서 p3는 Animal이라고 생각
	p3->age = 10;
	//p3->color = 1; // error

	// 핵심3. p3로 Dog 고유 멤버에 접근하려면 다운캐스팅
	// 단 이경우 p3가 가리키는곳이 반드시 Dog라는 확신필요
	// Dog 객체가 아니면 "잘못된 메모리 참조" 발생
	static_cast<Dog*>(p3)->color = 10;

	// 핵심4. 만약 조사가필요했다면 dynamic_cast를 사용하는 방법이있음
	Animal a;
	Animal* p4 = &a;

	// p4는 Dog가아닌 Animal 객체를 가리킴

	//Dog* pdog = static_cast<Dog*>(p4);  // 동작하지만 pdog 사용시 문제가 발생할수있음
	//									// --> staic_cast는 컴파일시 진행된다


	// p4가 가리키는 곳이 Dog인지 조사후 캐스팅 --> 맞으면 캐스팅, 틀리면 0
	Dog* pdog = dynamic_cast<Dog*>(p4); // 가상함수가 하나이상있어야 사용가능

	cout << p1 << endl;
	cout << p4 << endl;
	cout << pdog << endl;
}