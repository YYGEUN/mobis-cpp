#include <iostream>
using namespace std;

int f1(int a) { return a; } // a�� ���� ��ȯ�ϴ� �ڵ�
int& f2(int a) { return a; } // a�� ���۷����� ��ȯ�ϴ� �ڵ� (a�� ������ ��ȯ�ϴ°Ͱ� ����)

int main()
{
	// �Ϲ������� �Լ�ȣ���� �캯
	int ret = f1(5);
	
	// �Լ�ȣ���� �º��� ���δ� ��찡����
	// ex) v[0] = 10; == v.operator[](0) = 10;
	// --->
	//f1(7) = 10; // int�� int�� �Ҵ��Ҽ������� 7 = 10
	f2(8) = 10; // 
	cout << (f2(8)=10) << endl;
	cout << f2(8) << endl;
 	return 0;
}