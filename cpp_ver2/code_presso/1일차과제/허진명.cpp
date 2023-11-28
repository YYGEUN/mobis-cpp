// 1. mystrcopy 함수 만들기
// 2. myfilter 함수 만들기 (lambda)
// 3과 같은것, 4이상인 것, 3미만인것
// int arr[5] = {1, 2, 3, 4, 5};
#pragma warning (disable : 4996)
#include <iostream>

using namespace std;

void myStrCopy(char* str, const char* strstr) {
	int cnt = 0;
	while (strstr[cnt] != '\0') { cnt++; }
	
	char* tempStr = new char[cnt+1];
	for (int i = 0; i <= cnt; i++) {
		tempStr[i] = strstr[i];
	}
	str = tempStr;
}

void myFilter(int* arr, int size, bool(*fcPtr)(int)) {
	for (int i = 0; i < size; i++) {
		if (fcPtr(arr[i])) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	char* str = NULL;
	myStrCopy(str, "abcd");
	cout << str << endl;

	int arr[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	myFilter(arr, size, [](int arrNum)->bool {return arrNum == 3; });
	myFilter(arr, size, [](int arrNum)->bool {return arrNum > 3; });
	myFilter(arr, size, [](int arrNum)->bool {return arrNum < 3; });

	delete[] str;
	str = NULL;
	return 0;
}