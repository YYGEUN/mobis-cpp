#include <iostream>
using namespace std;

class Test {
private:
	int a, b;
public:
	Test() {
		cout << "const call" << endl;
		this->a = 0, this->b = 0;
	}
	Test(int a, int b) { cout << "arg call" << endl;
	this->a = a, this->b = b;
	}
	~Test() { cout << "dest call" << endl; }
	void SetData(int a, int b) { this->a = a, this->b = b; }
	void Show() { cout << "a = " << a << "b = " << b << endl; }
	friend void Fn();
	
	int operator+(int n) { return a + n; }
	friend int operator+(int n, const Test& t);
};

// 2항 연산자의 경우 
// 멤버함수 오버로딩 : 인자 1개
// 일반함수 오버로딩 : 인자 2개

int operator+(int n, const Test& t) {
	return n + t.a;
}

void Fn() {
	Test t;
	t.a = 10;
	t.b = 20;
}

int main() {
	//Fn();
	Test obj(10, 20);
	int rst;
	rst = obj + 110;
	cout << rst << endl;
	rst = 100 + obj; // 100.operator(obj) 불가 --> operatior(100,obj) 가능

	cout << rst << endl;

	int n = 10;


	return 0;
}