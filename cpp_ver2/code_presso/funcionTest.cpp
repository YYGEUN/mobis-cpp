#include <stdio.h>
#include <iostream>
using namespace std;

int g = 10;
void fn() {
	cout << "fn call" << endl;
}
namespace My 
{
	void fn() {
		cout << "My namespace fn call" << endl;
	}
}
using namespace My;
void myfn() {
	int g = 20;
	::g = 100;
}
int main()
{
	//myfn();
	//cout << "g=" << g << endl;
	::fn();
	My::fn();
	return 0;
}