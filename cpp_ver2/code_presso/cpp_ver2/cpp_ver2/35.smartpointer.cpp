#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <array>
#include <memory>

using namespace std;

class Test {
private:
	int a, b;
public:
	//Test() {
	//	cout << "const call" << endl;
	//	this->a = 0, this->b = 0;
	//}
	//Test(Test* T) {
	//	cout << "arg call" << endl;
	//	this->a = a, this->b = b;
	//}
	//~Test() { cout << "dest call" << endl; }
	void SetData(int a, int b) { this->a = a, this->b = b; }
	void Show() { cout << "a = " << a << "b = " << b << endl; }
};

template<typename T>
class smartPointer {
	T* ptr;
public:
	smartPointer(T* p) {
		ptr = p;
	}
	~smartPointer() {
		delete ptr;
	}
	T* operator->() {
		cout << "-> call" << endl;
		return ptr;
	}
	T& operator*() {
		return *ptr;
	}
};

int main() {
	smartPointer<Test> pt(new Test);

	pt->SetData(10, 20); // pt.operator->() pt->->setData(10,20)  compiler가 -> 두개를 하나로 합쳐버림
	pt->Show();

	auto_ptr<Test> p(new Test);

	array<int, 3> arr;
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	for (auto i : arr)
	{
		cout << i << endl;
	}

	return 0;
}
