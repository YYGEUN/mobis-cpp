#include <iostream>
#include <vector>

class Animal
{	
public:
	int age;
	virtual ~Animal() {}
};

class Dog : public Animal 
{
public:
	int color;
};

class Cat : public Animal 
{
public:
	int speed;
};


int main()
{
	std::vector<Animal*> v;

	// #1. v 에는 모든 동물을 넣을수 있습니다
	v.push_back( new Dog );
	v.push_back( new Cat );

	// #2. 하지만 v[0] 으로 멤버를 접근하면 Animal 멤버만 접근 가능합니다.
	auto n1 = v[0]->age; // ok
//	auto n2 = v[0]->color; // error

	// 해결책 1. dynamic cast

	if ( dynamic_cast<Dog*>(v[0]) ) // 결과가 0이 아니면 Dog 입니다.
	{
		// Dog 라고 확인이 되었으므로 Dog 로 캐스팅해서 사용합니다.
		// => Dog 라고 확신이 있으므로 여기서는 성능 저하없는 static_cast 를 사용하면 됩니다.
		Dog* dog = static_cast<Dog*>(v[0]);
		auto n2 = dog->color;
	}
	else if ( dynamic_cast<Cat*>(v[0]) ) 
	{
		Cat* cat = static_cast<Cat*>(v[0]);
		auto n2 = cat->speed;
	}
}