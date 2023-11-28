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
	//f���� ���ڰ� �Ѱ����Լ��� �������ִ�.
	// �׷��� std::bind �� �־� �ᱹ ���ڰ� 1���̻��� ����Լ��� �������ִ�.

	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1, 3);
	f(5); //dlg.close(5,3);

}