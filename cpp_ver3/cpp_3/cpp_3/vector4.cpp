//vector4.cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	//���������� {}�� ��������� �޸𸮸� �Ҵ�ް� �־� ���Ű� �Ұ����ϴ�

	int n=0,count=0;
	int size = 4;
	int* contain = new int[size];

	vector<int> v;

	while (1) {
		cin >> n;
		if (n == -1) 
			break;
		v.push_back(n);
		contain[count++] = n;
		if (count == size) {
			size *= 2;
			int* containtmp = new int[size];
			memcpy(containtmp, contain, sizeof(int) * size / 2);
			delete[] contain;
			contain = containtmp;
		}
		// �̺���� �Ѿ���鼭 containtmp �ı���
	}

	cout << "�Էµ� ���ڰ��� : " << count << endl;
	cout << "�Ҵ�� ����ũ�� : " << size << endl;

	for (int i = 0; i < size; i++) {
		cout << contain[i] << endl;
	}

	delete[] contain;

	return 0;
}


// list : ����Ҹ� ���� ���� --> �߰��� �ֱ� ����
// vector : ����Ҹ� ���ӵ� �޸𸮿� ���� --> �յڿ� �߰��ϴ°� ���� , ��ü��ȸ ����