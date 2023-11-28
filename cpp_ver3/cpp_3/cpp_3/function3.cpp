#include <iostream>
#include <functional>
//#include <stdio.h>

using namespace std::placeholders;

class Dialog
{
public:
	void close(int result, int arg) {}
};

void f4(int a, int b, int c, int d) {
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

void f1(int a) {
	printf("f1 : %d\n", a);
}

void f2(int a, int b) {
	printf("f4 : %d, %d\n", a, b);
}

int main()
{
	std::function<void(int)> f;
	f = std::bind(&f2, _1, 2);
	//f에는 인자가 한개인함수만 담을수있다.
	// 그런데 std::bind 가 있어 결국 인자가 1개이상인 모든함수를 담을수있다.

	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1, 3);
	f(5); //dlg.close(5,3);

}