#include <stdio.h>
#include <iostream>
using namespace std;

void myFilter(int* arr,int length, int Num, bool (*cmp)(int, int)) {
	for (int i = 0; i < length; i++) {
		if (cmp(Num, arr[i])) {
			cout << arr[i] << "  ";
		}
	}
	cout << endl;
}

void myStrcpy(char* A, const char* B) {
	int i = 0;
	while (1) {
		if (B[i] != NULL) {
			A[i] = B[i];
			i++;
		}
		else {
			A[i] = '\0';
			break;
		}
	}
}

int main() {
	int arr[5] = { 1,2,3,4,5 };
	char s[50];
	myStrcpy(s, "abcd dfasdg");
	printf("%s \n", s);
	
	int length = sizeof(arr) / sizeof(int);
	myFilter(arr, length, 3, [](int a, int b)->bool {return a < b; });
	myFilter(arr, length, 4, [](int a, int b)->bool {return a == b;});
	myFilter(arr, length, 3, [](int a, int b)->bool {return a > b; });

	return 0;
}

//1. strcopy �Լ��� ����ÿ�

//2. int arr[3] = {1,2,3,4,5};
//myfilter �Լ��� ����ÿ�(���� �� �̿��Ͽ�)
//3�� ���� �� 
//4 �̻� �� ��
//3 �̸��� ��