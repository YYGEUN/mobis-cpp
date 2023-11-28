#include <iostream>
#include <functional>
//#include <stdio.h>

using namespace std::placeholders;

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
	f4(1, 2, 3, 4);

	//void(*f)(int) = &f1;
	//f(10); // f1(10);
	//f = &f2; //error ������ ���°� �ٸ�

	//STL�� std::function �� �Լ� �����ͺ��� ��
	//���� : std::function<�Լ����>

	std::function<void(int)> f;
	f = &f1;
	f(10); //f1(10)
	
	//f = &f2; //error
	// std::function �� ���� -> std::bind�� ��ȯ�� ���� ����
	// �� 2���Լ� => 1���Լ� �� �����ؼ� ������ȴ�
	f = std::bind(&f2,_1, 3);
	f(5); // f2(5,3)

	f = std::bind(&f4, 3, 6, _1, 9);
	f(5); // f4(3,6,5,9)

}