#include <iostream>

using namespace std;

// c++

// �����ε�

// 1. �Լ��� �ߺ� ���
//	--> �Լ������ε�
// �Լ� �������,���°� �޶����
// ��ȯ���� �ٸ��Լ� �����ε� �Ұ�

//call by value --> ���� ����
//call by pointer --> �����氡��, ��������̾��� ����(value�� �ӽð��� ������ �纹�簡 �̷���)

void output() {
	cout << "���\n";
}

void output(int num = NULL) { // num ���� �̸� �ʱ�ȭ�ϴ°͵� ����
	cout << "�Է¹����� :" << num << endl;
}

void output(float num) {
	cout << "�Է¹����� :" << num << endl;
}

void swap1(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int& makeNum() {
	int num = 7;

	return num;
	//return �� ���ÿ� num�� ���������μ� �Ҹ��
}

int main() {

	int a = 8;
	// b�� a�� ������ �Ҵ� ���� �ּҰ��� �״�ΰ���
	int& b = a;
	// c�� a�� �Ҵ� �����޸��ּҸ� ����Ŵ
	int* c = &a;

	cout << &a << endl;
	cout << &b << endl;
	cout << c << endl;

	int num1 = 1;
	int num2 = 2;

	swap1(num1, num2);

	cout << num1 << "   " << num2 << endl;

	swap2(&num1, &num2);

	cout << num1 << "   " << num2 << endl;

	// ��� ����
	const int n = 111;

	//�Ұ����� ����) ��������ڴ� ���� �����ڸ� ���� �Ұ�
	//int& ref = n;
	//���� ����)
	const int& refn = n;
	const int& refnn = 100;
	//�� ������ 100�̶�� �ӽð��� �����ߴٰ� �����࿡�� �Ҹ�  (�ӽ� �� 100�� �����Ͽ� �����ϰ� refnn�� �ְ� �Ҹ�)


	//& ref ���� ����
	int& ran = makeNum();
	//���������� �Լ��� �����鼭 �޸𸮼Ҹ� --> �Ҹ�� �޸� ������ ��������
	//Dangling REF ���� �̶���� (������ �޸𸮸� �����ϴ� ������)

	int& np = a;

	//1.�迭Ÿ��
	//2.const Ÿ��
	//3.�ҿ���Ÿ��

	return 0;
}