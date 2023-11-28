#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

void rfn( const int& n){
	cout << n << endl;
}
void pfn(const int* p){
	cout << *p << endl;
}

const int returnValue(){ 
	return 100;
}

constexpr int arrsize() {
	return 5;
}

const int* returnP() {
	int* p = new int;
	*p = 100;
	return p;
}
const int& returnR() {
	//int num = 10;
	int* p = new int;
	*p = 100;
	return *p;
}
int main() {
	const int x = 10;
	int y = 20;
	const int* const p = &x;
	//*p = 100; X
	//p = &y; x
	//rfn(y);
	//pfn(&yt
	//int rst;
	//rst = returnValue();
	//int arr[arrsize()];

	//const int* pa = returnP();
	//cout << *pa << endl;
	////*pa = 200;
	//delete pa;
	const int& r = returnR();
	cout << r << endl;

	delete& r;

	return 0;
}


