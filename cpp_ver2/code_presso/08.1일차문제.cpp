/*
1. mystrcopy함수를 만드시요

char s[50];
mystrcpy(s, "abcd");
printf("%s\n", s); //abcd

2. int arr[5] = { 1,2,3,4,5 };
myfilter 함수를 만드시요 (람다식)
3과 같은것
4이상인것
3미만인것

1일차과제 
본인성함.cpp


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