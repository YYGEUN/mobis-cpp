// virtual2.cpp
#include <iostream>

class Base
{
public:
};
class Derived : public Base
{
public:
	Base()  { std::cout << "메모리할당\n";}
	~Base() { std::cout << "메모리해지\n";}
};
int main()
{
	Derived d;
}