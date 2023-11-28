#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;


template<typename T, typename U>
decltype(auto) add(T t, U u) {
	return t + u;
}

template<typename T, typename U>
auto gop(T t, U u) {
	return t * u;
}

//auto myfn(auto a, auto b) {
//	return a + b;
//}

//람다만 가능 14 이후부터
auto lambda = [](auto x, auto y) {
	return x + y;
};


int main()
{
	int rst = lambda(100, 200);
	cout << rst << endl;
	/*
	auto a = 10;
	auto b = 3.14;
	int x = 100;
	decltype(x) y = 20; 

	double aa = 5.0;
	int bb = 3;
	decltype(aa * bb) result = 3.4;


	cout << typeid(a).name() << " " << sizeof(a) << " " << a << endl;
	cout << typeid(b).name() << " " << sizeof(b) << " " << b << endl;
	cout << typeid(y).name() << " " << sizeof(y) << " " << y << endl;
	*/
	return 0;
}