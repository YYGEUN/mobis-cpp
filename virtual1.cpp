#include <iostream>
class Animal
{
public:
	void cry1() { std::cout << "Animal cry1\n"; }
};

class Dog : public Animal 
{
public:

};

int main()
{
	Animal a; a.cry1();
	Dog    d; d.cry1();

	Animal* p = &d;
	p->cry1();
}