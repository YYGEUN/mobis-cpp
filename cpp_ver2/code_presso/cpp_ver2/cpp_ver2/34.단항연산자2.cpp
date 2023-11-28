#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;


class Pointer {
	int* ptr;
public:
	Pointer(int* p) {
		ptr = p;
	}
	~Pointer() {
		delete ptr;
	}
	int& operator*() {
		return *ptr;
	} 
};

template<typename T>
class smartPointer {
	T* ptr;
public:
	Pointer(T* p) {
		ptr = p;
	}
	~Pointer() {
		delete ptr;
	}
	T& operator*() {
		return *ptr;
	}
};


template<typename T,typename S> // typename == class와 같은의미
class TempClass
{
	T t;
	S s;
public:
	void SetT(T a) { t = a; }
	T GetT() { return t; }
};

int main()
{
	TempClass<int, double> tt;
	tt.SetT(10);
	cout << tt.GetT() << endl;

	/*
	Pointer my(new int);
	*my = 10; //my.operator*() = 10;
	cout << *my << endl; 
	*/
	return 0;
}