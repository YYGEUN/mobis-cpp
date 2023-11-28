#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

struct Test {
	int a;
	int b;
};
int main()
{
	Test* p = new Test{ 11,22 };
	cout << "p->a=" << p->a << endl;
	cout << "p->b=" << p->b << endl;
	delete p;

	Test* pa = new Test[3]{ {1,2},{11,22},{33,44} };
	pa[0].a = 10;
	//p->a = 10; // (*p).a = 10;
	pa[1].a = 100;
	//(p + 1)->a = 100; // (*(p+1)).a = 100;
	delete[] pa;

	return 0;
}


