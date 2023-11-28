#include <stdio.h>
#include <iostream>
using namespace std;

//함수 오버로딩..
// 함수이름은 동일하지만 인자의 갯수나 타입이틀린경우 
//컴파일러에 의한 네임맹글링 
//sumii
int sum(int a, int b) { 
	return a + b;
}

// sumdd
double sum(double a, double b) {
	return a + b;
}

extern "C" //name mangling 적용 x
void myfn() {
	printf("aa\n");
}

template <typename T, typename S>
T gop(T a, S b){
	return a * b;
}

void fn(int a = 10, int b = 20, int c = 30) {
	cout << "a=" << a << " b=" << b << " c=" << c << endl;
}

struct Test {
	Test(int a, int b) {
		this->a = a;
		this->b = b;
	}
	int a;
	int b;
};
void testFn( const Test& tt) {
	cout << tt.a <<"  "<< tt.b << endl;
}
int main(){

	fn();
	fn(100);
	fn(100, 200);
	Test tt{ 100,200 }; 
	//Test tt(100, 200);
	//Test tt;
	//tt.a = 100;
	//tt.b = 200;
	testFn(tt); //named parameter

	//fn(c = 1000); x
	/*
	int rst;
	rst = sum(10, 20); //sumii(10,20)
	double drst;
	drst = sum(1.1, 1.2); //sumdd(1.1, 1.2)
	//rst = gop<int, int>(100, 200);
	rst = gop(100, 200);
	cout << rst << endl;
	//drst = gop<double, double>(3.1, 2.4);
	drst = gop(3.1, 2.4);
	cout << drst << endl;
	string s;
	//s = gop<string, string>("abc", "def");
	//cout << s << endl;*/
	return 0;
}






