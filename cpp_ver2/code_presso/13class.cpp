#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;


class Test {
private:
	int a;
	int b;
public:
	//void setData(Test* this, int x, int y)
	void setData(int x, int y){
		printf("setdata this:%d\n", this);
		a = x; //this->a = x
		b = y; //this->b = y
	}
	//void show(Test* this)
	void show() {
		printf("show this:%d\n", this);
		cout << "a=" << a << " b=" << b << endl;
		//cout << "a=" << this->a << " b=" << this->b << endl;
	}
	//Test(){}
};
int main() {

	// 
	Test* p = new Test;
	p->setData(10, 20);//p->setData(p,10, 20);
	p->show();//p->show(p,10, 20);
	delete p;

	return 0;
}