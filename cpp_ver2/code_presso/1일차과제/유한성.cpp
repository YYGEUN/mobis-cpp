#include <iostream>
#include <stdio.h>
#include <typeinfo>

using namespace std;

/*1.mystrcpy 함수 만들기
* 2. myfilter 함수를 만들기 (조건 : 람다식 이용)
* 3과 같은것 4이상인것 3미만인 것
* 1일차 과제 본인성함.cpp로
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
	myfilter(arr, 5, 3, [](int a, int b)->bool{return a == b; }); //3과 같은 것
	cout << endl;
	myfilter(arr, 5, 4, [](int a, int b)->bool{return a >= b; }); //4 이상인 것
	cout << endl;
	myfilter(arr, 5, 3, [](int a, int b)->bool{return a < b; }); //3 미만인 것

	return 0;
}