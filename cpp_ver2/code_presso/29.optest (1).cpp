#include <iostream>
#include <string>
using namespace std;

/*
반환형 operator연산자(매개 변수 목록)
{
	....// 연산 수행
}
*/

class Test {
private:
	int a; int b;
public:
	Test() {
		this->a = 0; this->b = 0;
		cout << "constructor call" << endl;
	}
	Test(int x, int y) {
		a = x; b = y;
		cout << "arg constructor call" << endl;
	}
	~Test() {cout << "dest call" << endl;}
	Test(const Test& r) {
		cout << "copy const call" << endl;
		this->a = r.a;
		this->b = r.b;
	}
	Test& operator=(const Test& r){
		cout << "= op call " << endl;
		this->a = r.a;
		this->b = r.b;
		return *this;
	}
	void setData(int x, int y) {
		a = x;b = y;
	}
	void show() {cout << "a=" << a << " b=" << b << endl;}
	// 일반적으로 연산자오버로딩( 멤버함수:인자갯수1개, 일반함수: 2개)
	int operator+(int n) {
		cout << "op + call " << endl;
		return this->a + n;
	}
	int operator-(int n) {
		cout << "op - call " << endl;
		return this->a - n;
	}
	//operator+(Test* this,const Test& n)
	Test operator+(  Test& n) 
	{
		//Test t;
		//t.a = this->a + n.a;
		//t.b = this->b + n.b;
		//return t;
		//Test t(this->a + n.a, this->b + n.b);
		//return t;
		return Test(this->a + n.a, this->b + n.b);
	}
	//obj3 = obj1 + obj2;
};
int main() {
	int rst;
	Test obj;
	obj.setData(10, 20);
	//rst = obj + 100; //obj.operator+(100)
	rst = obj - 100; //obj.operator-(100)
	cout << "rst=" << rst << endl;
	// obj = obj1; obj.operator=(obj1)
	// 10분 퀴즈..
	Test obj1(10, 20);
	Test obj2(100, 200);
	Test obj3;
	obj3 = obj1 + obj2; // obj1.operator+(&obj1, obj2 )
	obj1.show(); // 10,20
	obj2.show(); // 100,200
	obj3.show(); // 110,220
	return 0;
}


