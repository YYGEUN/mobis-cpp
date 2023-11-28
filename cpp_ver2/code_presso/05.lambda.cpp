#include <stdio.h>
#include <iostream>
using namespace std;

// clean code: 함수 정의
//1. 하나의 기능만수행
//2. 중복기능을 분리:(람다(함수포인터), 클래스(인터페이스)) 
void Swap(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

bool cmpAsc(int a, int b) {
	return a > b;
}
bool cmpDesc(int a, int b) {
	return a < b;
}

void Sort(int* x, int n, bool (*cmp)(int,int) ) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			/*if (x[i] > x[j]) {*/
			if( cmp( x[i],x[j] ) ){
				Swap(x[i], x[j]);
			}
		}
	}
}
int hap(int a, int b) {
	return a + b;
}
int main()
{

	//람다함수: 익명함수 임시함수
	// [](아규먼트) -> 리턴타입 {  } 
	int (*phap)(int, int) = hap;
	phap(100, 200);
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	//Sort(x, 10, cmpAsc);
	//Sort(x, 10, cmpDesc);
	//Sort(x, 10, [](int a, int b)->bool { return a > b; } );
	Sort(x, 10, [](int a, int b)->bool { return a < b; });
	// 11버전이후 지원되는 문법
	for (int n : x) {
		cout << n << endl;
	}
	return 0;
}