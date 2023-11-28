#include <iostream>
#include <typeinfo>
using namespace std;

class Test {
private:
	int a, b;
public:
	Test() {
		cout << "const call" << endl;
		this->a = 0, this->b = 0;
	}
	Test(int a, int b) {
		cout << "arg call" << endl;
		this->a = a, this->b = b;
	}
	~Test() { cout << "dest call" << endl; }
	void SetData(int a, int b) { this->a = a, this->b = b; }
	void Show() { cout << "a = " << a << "b = " << b << endl; }
	friend ostream& operator<<(ostream& o, const Test& t);
};

ostream& operator<<(ostream& o, const Test& t) {
	o << "a = " << t.a << "b = " << t.b;
	return o;
}

int main() {
	cout << typeid(cout).name() << endl;

	Test obj(10, 20);
	//cout << obj; //cout.operator<<(obj) 불가 --> operator(cout,obj) 일반함수로 해결
	cout << obj << endl; // operator(cout,obj) > return cout --> opearator(cout,'\n') // 왼쪽부터

	return 0;
}