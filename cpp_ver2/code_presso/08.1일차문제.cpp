/*
1. mystrcopy�Լ��� ����ÿ�

char s[50];
mystrcpy(s, "abcd");
printf("%s\n", s); //abcd

2. int arr[5] = { 1,2,3,4,5 };
myfilter �Լ��� ����ÿ� (���ٽ�)
3�� ������
4�̻��ΰ�
3�̸��ΰ�

1�������� 
���μ���.cpp


*/

#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

void mystrcpy(char* dst, const char* src)
{
	int cnt = 0;
	while (true) {
		//*dst = *src
		//*dst++ = *src++;
		dst[cnt] = src[cnt];
		if (dst[cnt] == 0) // *dst == 0;
			break;
		cnt++;
		//dst++;
		//src++;
	}
}
void myFilter( int* arr, int size, bool (*cmp)(int) )
{
	for (int i = 0; i < size; i++) {
		//if( arr[i]>=3)
		if (cmp( arr[i] ) )
			printf("%d\n", arr[i]); 
	}
}

int main(){
	char s[50];
	mystrcpy(s, "abcd");
	printf("%s\n", s);

	int arr[5] = { 1,2,3,4,5 };
	myFilter(arr, 5, [](int n) { return n >= 2; });
	//myFilter(arr, 5, [](int n)->bool { return n >= 3; });

	return 0;
}