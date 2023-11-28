#include <iostream>
#include <functional>
//#include <stdio.h>

using namespace std::placeholders; // _1 �� ����ϱ�����

void f4(int a, int b, int c, int d) {
	//������ ������ ����Ҷ��� printf�� ����
	printf("f4 : %d, %d, %d, %d\n",a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4);

	//std::bind N�� �Լ��� �Ϻ�(����) ���ڸ� ������ ���ο� �Լ��� ����� ����

	auto f0 = std::bind(&f4, 5, 2, 3, 4); // f4�� ���� 4���� ��� ������ ���ο��Լ�
	f0(); //f4(1,2,3,4); --> 4�� �Լ��� 0�� �Լ��� �ٲ�

	auto f2 = std::bind(&f4, 6, _1, 7, _2);
	f2(3, 9); // f4(6,3,7,9) 4���Լ��� 2���Լ���

	auto f3 = std::bind(&f4, _2, _3, 8, _1);
	f3(9, 3, 7); // f4(3,7,8,9)

}