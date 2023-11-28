#include <stdio.h>
#include <iostream>

using namespace std;

/*1. mystrcopy �Լ� �����
  char s[50];
  mystrcopy(s, "abcd");
  printf("%s\n", s); ���� �� abcd�� ��µǰ� */
void myStrcpy(char* str, const char* target) {
	int idx = 0;
	while (*target != NULL) {
		str[idx] = *target;
		idx++;
		target++;
	}
	
}

/*2. int arr[5] = {1, 2, 3, 4, 5};
  myfilter �Լ��� ����ÿ� (���ٽ� Ȱ��)
  ex. 3�� ���� �� */
void myFilter(int* arr, int size, bool (*cmp)(int)) {
	for (int i = 0; i < size; i++) {
		if (cmp(arr[i])) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

int main() {
	
	cout << "����  1�� ����" << endl;
	char s[50] = { 0, };
	myStrcpy(s, "abcd");
	printf("%s\n", s);


	cout << "����  2�� ����" << endl;
	int arr[5] = { 1, 2, 3, 4, 5 };
	cout << "3 �̻��� ���" << endl;
	myFilter(arr, 5, [](int a)->bool {return a >= 3; });
	cout << "2 �̸��� ���" << endl;
	myFilter(arr, 5, [](int a)->bool {return a < 2; });

	return 0;
}

