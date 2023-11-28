#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

/*1.mystrcpy �Լ� �����
* 2. myfilter �Լ��� ����� (���� : ���ٽ� �̿�)
* 3�� ������ 4�̻��ΰ� 3�̸��� ��
* 1���� ���� ���μ���.cpp��
*/

void mystrcopy(char* s, const char* str)
{
	for (int i = 0; i <= sizeof(str)/sizeof(char); i++)
	{
		s[i] = str[i];
	}

}

void myfilter(int* arr,int n, int a, bool(*cmp)(int ,int ))
{
	for (int i = 0; i < n; i++) {
		if (cmp(arr[i], a))
		{
			printf("%d ", arr[i]);
		}
	}
}


int main()
{
	char s[50];
	mystrcopy(s,"abcd 111");
	printf("%s\n", s);
	
	int arr[5] = { 1,2,3,4,5 };
	myfilter(arr, 5, 3, [](int a, int b)->bool{return a == b; }); //3�� ���� ��
	cout << endl;
	myfilter(arr, 5, 4, [](int a, int b)->bool{return a >= b; }); //4 �̻��� ��
	cout << endl;
	myfilter(arr, 5, 3, [](int a, int b)->bool{return a < b; }); //3 �̸��� ��

	return 0;
}