//vector3.cpp
#include <iostream>

using namespace std;

int main()
{
	int cnt;

	cout << "�л��� ����ΰ��� >> ";
	cin >> cnt;

	int* a = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		cin >> a[i];
	}

	delete a;

	return 0;
}
