#include <iostream>
#include <initializer_list>

using namespace std;

int Accel(int i) {
	return i + 1;
}

typedef struct person {
	int age;
	int sex;
};

int main() {
	if (int want = Accel(50); want <= 60) {
		cout << "ok" << endl;
	}

	// �����Ҵ�
	// new(new alloc) Ű����
	// delete �޸� ��ȯ�ϴ� Ű����
	// ������

	person* p1 = new person;
	p1->age = 27;
	cout << p1->age << endl;
	delete p1;

	/*
	�迭 �����Ҵ� + ��������� �ʱ�ȭ��Ŵ
	int* score = new int[3]{ 1,3,5 };
	cout << score[1] << endl;
	delete[] score;
	*/

	//2���� �迭 �����Ҵ�
	int** diction = new int* [5];
	for (int i = 0; i < 5; i++) {
		diction[i] = new int[10] {1, 2, 3, 4, };
	}

	for (int i = 0; i < 5; i++) {
		delete[] diction[i];
	}

	int cnt = 0;
	int x = 7, y = 5;
	int** score = new int* [y];
	for (int i = 0; i < y; i++)
	{
		score[i] = new int[x];
		for (int j = 0; j < x; j++) {
			score[i][j] = cnt;
			cnt++;
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++) {
			cout << score[i][j] << "    ";
		}
		cout << endl;
	}


	auto score2 = new int[2][3];

	for (int i : score2[0]) {
		cout << &i << endl;
	}

	//for (int(&i)[3] : score2)
	//{
	//	for (int&j:i) {
	//		cout << j << "    ";
	//	}
	//	cout << endl;
	//}

	for (int j = 0; j < y; j++) {
		delete[] score[j];
	}
	delete[] score;

	int cnt2=0;
	int* imsi = new int[10];
	int imsi2[10] = { 0, };
	for (int i = 0; i < 10; i++) {
		imsi[i] = i;
	}
	int i = 0;
	for (auto element : imsi2) {
		element = i;
	}

	//�����Ҵ��� �����ϴܰ迡�� ��� �迭�ڸ������ �����迭�� �ҷ����� �ȵ�
	//for (auto element : imsi) {
	//	element = i;
	//}



	cout << endl;

	return 0;
}