#include <iostream>

//using -> type,templete ���밡��
// ex) using DWORD = int;
// ex) using callbackF = void(*)(void*);
//typedef -> type�� ����
// typedef void(*callbackF)(void*);
// typedef const char* ObjectName;

typedef struct abc {
	int a;
}ABC,*PABC;

using namespace std;



// �ڵ��ۼ��� ������,�Լ��� �ߺ�����ϰ������
// ��Ģ�� �ߺ���� �Ұ� --> namespace ������ �ذᰡ��
// ������ �ڵ��ۼ����� ������,�Լ��� �浹�� ��������

namespace engine
{
	double temp = 25;
	void output() {
		cout << "���� �µ� : " << temp << endl;
	}
}

namespace incar
{
	double temp = 25;
	void output() {
		cout << "���� �µ� : " << temp << endl;
	}
}

namespace calculate {
	int getdis(float a1, float b1, float a2, float b2)
	{
		float dist;
		dist = sqrt(pow((a1 - b1), 2) + pow((a2 - b2), 2));
		return dist;
	}
}

int main() {
	// :: �������� ������ 
	// Ŭ�����������̻�� 
	// ȣ���� �Լ�,������ �����ǰ����� ���

	int num(3); // == int num{3})({} �ǰ�� �����Ѽ��� ��Ģ-- ����ȯ�� �¾ƾ���) ���𹮿��� �� ���ѹ� ��밡�� int num = 3�� ����
	int arr[3]{ 1,2,3 }; // �迭�� ����

	engine::temp = 45.0;
	incar::temp = 22.0;

	engine::output();
	incar::output();

	//int aa{3.3f}; // �Ұ�
	int aa(3.3f); // ���� ������ float �ս�

	//char c('a');
	char c{ 97 };

	cout << c << endl;


	int money = 1'000'000; // �ڸ��� ǥ������
	int cc = 0x00b;

	cout << money << endl;

	cout <<  << endl;
	return 0;
}