#include <iostream>
#include <string>
using namespace std;

class Test {
private:
	//int a=0;
	//int b=0;
	//const double R=3.14;
	int a;
	int b;
public:

	Test(int x, int y){
		//R = 3.14;
		a = x;
		b = y;
		cout << "arg constructor call" << endl;
	}

	~Test() {
		cout << "dest call" << endl;
	}
	void setData(int x, int y) {
		a = x;
		b = y;
	}
	void show() {
		cout << "a=" << a << " b=" << b << endl;
	}
	Test() //Test(Test* this)
	{
		this->a = 0;
		this->b = 0;
		cout << "constructor call" << endl;
	}
	//Test r =tt
	Test(const Test& r)//Test(Test* this,const Test& r) 
	{
		cout << "copy const call" << endl;
		this->a = r.a;
		this->b = r.b;
	}
	explicit Test(int n) {
		cout << "one arg const call" << endl;
		this->a = n;
		this->b = 0;
	}
};
// 복사생성자를 정의 하지 않으면 컴파일러 make해준다.
void fn(Test v)
{
	v.show();
}
void fn(int n) {
	cout << n << endl;
}
//Test v = tt; Test v(tt);  v.Test( &v, tt )
void fn1(Test v) {
	v.show();
}
void callByValue(Test v) 
{
	v.setData(100, 200);
}
void callByRef(Test& r) {
	
	r.setData(100, 200); //r.setData(&r,100,200);
}
void callByPointer(Test* p) {
	p->setData(100, 200);//p->setData(p,100,200);
}

int main()
{
	Test tt;
	//callByValue(tt);
//allByRef(tt);
	callByPointer(&tt);
	tt.show();

	//fn1(tt);
	//fn(100);

	/*
	Test tt; 
	//tt.Test( &tt )
	tt.setData(100, 200);
	//Test ss(tt); //복사생성자 호출
	//ss.Test( &ss, tt )
	//Test ss = Test(tt);
	Test ss = tt;
	ss.show();
	Test uu = 10; //Test uu(10);
	*/
	return 0;
}