// shape1.cpp

class Animal
{
public:
	int age;
};

class Dog : public Animal 
{
public:
	int color;
};

int main()
{
	Dog dog;
	Dog*    p1 = &dog;
	int*    p2 = &dog;
	Animal* p3 = &dog;
}