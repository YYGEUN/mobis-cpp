#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void mystrcpy(char* s, const string& a) {
	int i;
	for (i = 0; i < a.size(); i++) {
		s[i] = a[i];
	}
	s[i] = '\0';
	printf("%s\n", s);
}

void myfilter(int* arr, int n, bool (*cmp)(int)) {
	for (int i = 0; i < n; i++) {
		if (cmp(arr[i])) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}


int main() {
	//1. mystrcopy �Լ��� ����ÿ� char s[50]; mystrcpy(s, "abcd") printf("%s\n",s);
	char s[50];
	string a = "abcd";
	mystrcpy(s, a);


	//2. ���ٽ����� int arr[3] = {1,2,3,4,5} myfilter �Լ��� ����ÿ�. (3�� ���� ��, 4�̻��� ��, 3�̸��� ��)
	int arr[5] = { 1,2,3,4,5 };
	myfilter(arr, 5, [](int x) { return x == 3; });
	myfilter(arr, 5, [](int x) { return x >= 4; });
	myfilter(arr, 5, [](int x) { return x < 3; });

}
