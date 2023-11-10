// shape1.cpp

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 상속을 사용할때
						// 모든 기반 클래스 소멸자는 반드시
						// 가상함수이어야 합니다
						// "무조건 기반 클래스 만들때는 소멸자를 가상으로 하세요!"
};
class Dog : public Animal 
{
public:
	int color;
};
int main()
{
	Dog dog;

	Dog*    p1 = &dog; // ok
	int*    p2 = &dog; // error.
	Animal* p3 = &dog; // ok

	// 핵심 1. 파생 클래스 객체의 주소를 기반 클래스 포인터에 담을수 있다
	// => upcasting 이라는 개념 

	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능
	// => 컴파일러는 p3 가 가리키는 곳은 Animal 이라고만 생각한다.
	p3->age   = 10; // ok
//	p3->color = 10; // error


	// 핵심 3. p3로 Dog 고유 멤버에 접근하려면 캐스팅 해야 한다.
	// => 단 이경우 p3 가 가리키는 곳이 반드시 Dog 객체라는 확신이 있어야 한다.
	// => Dog 객체가 아니면 "잘못된 메모리 참조" 발생
	static_cast<Dog*>(p3)->color = 10; // ok

	// 핵심 4. 만약 조사가 필요 했다면 "dynamic_cast" 를 사용하는 방법이 있긴 합니다.

	Animal a;
	Animal* p4 = &a;

	// 현재 p4 는 Dog가 아닌 Animal 객체를 가리키지만
//	Dog* pdog = static_cast<Dog*>(p4); // 이 코드는 정상적으로 동작합니다
									   // pdog 사용시 오류 발생할수 있습니다

	// 아래 처럼 하면 p4가 가리키는 곳인 Dog 인지 조사후 캐스팅하게 됩니다.
	Dog* pdog = dynamic_cast<Dog*>(p4);

	std::cout << p4   << std::endl; 
	std::cout << pdog << std::endl; 
}

//<iostream> 포함하고 실행해 보세요