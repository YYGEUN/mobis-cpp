#include <iostream>
#include <vector>

// 해결책 #2. save 기능을 객체 자신이 책임을 지게 하는 방법
// => 객체가 스스로 파일을 저장할수 있는 기능 제공
// => 구조가 복잡해 보일수 있지만.. 해결책 1. 보다는 객체지향 설계의 보다 충실한 디자인 입니다.

class Animal
{	
public:
	int age;
	virtual ~Animal() {}

	void save(FILE* f)
	{
		std::cout << "모든 동물의 공통의 특징 age 를 파일에 저장\n";

		// 이제 파생 클래스 고유의 멤버도 저장되어야 합니다.
		save_state(f);
	}

	virtual void save_state(FILE* f) {}
};

// 이제 파생 클래스는 자신의 고유한 멤버를 저장하기 위해 
// save_state() 를 override 합니다.
class Dog : public Animal 
{
public:
	int color;

	virtual void save_state(FILE* f) 
	{
		std::cout << "자신이 Dog 라는 정보를 저장하고\n";
		std::cout << "자신의 고유 멤버를 저장\n";
	}
};

int main()
{
	std::vector<Animal*> v;

	// v 에는 모든 동물을 넣을수 있습니다
	v.push_back( new Dog );

	FILE* f = nullptr;  // 파일을 오픈하고 하는 코드 작성

	// 1. 파일에 v.size() 를 먼저 저장 - 몇개의 객체인지 정보 저장
	// 2. 각 객체의 정보를 파일에 저장합니다.

	for( auto e : v)
	{
		e->save(f); // 모든 객체 저장
					// 1. Animal 의 공통의 멤버가 먼저 저장 되고
					// 2. save_state()를 통해서 파생 클래스 고유의 멤버가 저장되게 됩니다.
	}
}

// 파일로 부터의 load 는 어떻게 할지의 고민이 필요 합니다.

// 저장 : "만들어진 객체"를  파일에 저장 인데
// 복구 : 파일의 정보로 부터 "객체의 생성" 입니다.

// 객체가 파일에 저장되었다고 복구 될수 있는 것을
// 객체에 "영속성(persistence) 을 부여했다" 라는 용어를 사용하기도 합니다.
