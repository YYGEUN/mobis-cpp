//vecto11.cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	//���������� {}�� ��������� �޸𸮸� �Ҵ�ް� �־� ���Ű� �Ұ����ϴ�

	int n = 0;
	//int size = 4;
	//int* score = new int[size];

	vector<int> v;

	while (1) {
		cin >> n;
		if (n == -1)
			break;
		v.push_back(n);
		//score[count++] = n;
		//if (count == size) {
		//	size *= 2;
		//	int* containtmp = new int[size];
		//	memcpy(containtmp, score, sizeof(int) * size / 2);
		//	delete[] score;
		//	score = containtmp;
		//}
		// �̺���� �Ѿ���鼭 containtmp �ı���
	}

	cout << "�Էµ� ���ڰ��� : " << v.size() << endl;
	cout << "�Ҵ�� ����ũ�� : " << v.capacity() << endl;

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i] << endl;
	//}

	for (int i : v) {
		cout << i << endl;
	}

	//delete[] score;

	return 0;
}


// list : ����Ҹ� ���� ���� --> �߰��� �ֱ� ����
// vector : ����Ҹ� ���ӵ� �޸𸮿� ���� --> �յڿ� �߰��ϴ°� ���� , ��ü��ȸ ����