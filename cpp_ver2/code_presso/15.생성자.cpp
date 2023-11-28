#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

//생성자:객체생성시 자동호출 되는 함수
class Test {
private:
	int a;
	int b;
public:
	Test() //Test(Test* this)
	{
		cout << "constructor call" << endl;
		a = 0; //this->a = 0
		b = 0; //this->b = 0
	}
	//암시적호출을 금지하여 버그를 없앤다..
	explicit Test(int n )
	{
		cout << "one arg constructor call" << endl;
		a = n; 
		b = 0;
	}
	Test(int x, int y) {
		cout << "arg constructor call" << endl;
		a = x;
		b = y;
	}
	~Test() {
		cout << "dest call" << endl;
	}

	void setData(int x, int y) {
		a = x; //this->a = x
		b = y; //this->b = y
	}
	void show() {
		cout << "a=" << a << " b=" << b << endl;
	}
};

void Fn(Test t) {
	cout << "fn call" << endl;
	t.show();
}
void myfn()
{
	//Test tt;
	//tt.show();
	Test* p = new Test; //memory leak
	printf("p=%d\n", p);
	p->show();
	delete p;
}
int main() {
	myfn();
	myfn();
	myfn();
	cout << "hello" << endl;
	//Test tt;
	//Test tt = Test();// 명시적호출
	//tt.Test( &tt )
	//Test ss(10, 20);
	//Test ss = Test(10, 20); //명시적
	//ss.Test(&ss, 10,20)
	//Test uu(100);
	//Test uu = Test(100);//명시적
	//Test uu = 100; //암시적호출
	//Fn(30);

	return 0;
}

