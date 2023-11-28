#include <iostream>
#include <string>
using namespace std;


class Test {
private:
	int a;
	int b;
public:
	Test(int x, int y) {
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
	Test()
	{
		this->a = 0;
		this->b = 0;
		cout << "constructor call" << endl;
	}
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

	//est& operator=(Test*this, const Test&r )
	Test& operator=(const Test& r)
	{
		cout << "= op call " << endl;
		this->a = r.a;
		this->b = r.b;
		return *this;
	}
};
int main() {


	return 0;
}