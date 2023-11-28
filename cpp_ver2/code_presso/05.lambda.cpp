#include <stdio.h>
#include <iostream>
using namespace std;

// clean code: �Լ� ����
//1. �ϳ��� ��ɸ�����
//2. �ߺ������ �и�:(����(�Լ�������), Ŭ����(�������̽�)) 
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

	//�����Լ�: �͸��Լ� �ӽ��Լ�
	// [](�ƱԸ�Ʈ) -> ����Ÿ�� {  } 
	int (*phap)(int, int) = hap;
	phap(100, 200);
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	//Sort(x, 10, cmpAsc);
	//Sort(x, 10, cmpDesc);
	//Sort(x, 10, [](int a, int b)->bool { return a > b; } );
	Sort(x, 10, [](int a, int b)->bool { return a < b; });
	// 11�������� �����Ǵ� ����
	for (int n : x) {
		cout << n << endl;
	}
	return 0;
}