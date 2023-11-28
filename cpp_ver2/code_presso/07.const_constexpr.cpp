#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

constexpr int arrsize() {
	return 5;
}

const int fn(int x) {
	return x;
}

int main(){

	const int x = 10;
	const int* ptr3 = &x;
	cout << *ptr3 << endl;

	int x1 = 10;
	int x2 = 20;
	int* const ptr1 = &x1;
	*ptr1 = 100;
	//ptr1++;
	//ptr1 = &x2;
	const int* ptr2 = &x2;
	//*ptr2 = 200;
	int x3 = 3;
	const int& r = x3;
	x3 = 100;
	//r = 100;

	/*
	// const 컴파일, 런타임
	// constexpr 컴파일타임만
	const int x = 10; //x readonly
	//x = 100;
	int y;
	y = 200;
	const int z = y;
	constexpr int aa = 10;
//	aa = 100;
	//int bb = 10;
	//constexpr int cc = bb; //에러발생
	int nsize = 5;
	int arr[arrsize()];
	*/



	return 0;
}