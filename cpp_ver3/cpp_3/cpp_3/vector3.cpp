//vector3.cpp
#include <iostream>

using namespace std;

int main()
{
	int cnt;

	cout << "학생이 몇명인가요 >> ";
	cin >> cnt;

	int* a = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		cin >> a[i];
	}

	delete a;

	return 0;
}
