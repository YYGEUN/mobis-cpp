#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

struct Test {
	int a=11;
	int b=22;
	//Test(){}
	Test(int x=1, int y=2) : a(x), b(y) {}
};

int main()
{
	//멤버데이터 초기화
	//Test tt = { 1,2 };
	//Test tt{ 1,2 };
	//Test tt{};
	//Test tt(100,200); 
	//1.Test tt 2.tt.Test(100,200)
	Test tt;
	cout << "tt.a=" << tt.a << endl;
	cout << "tt.b=" << tt.b << endl;

	//Test* p = new Test;
	//(*p).a = 100; //p->a = 100;
	//(*p).b = 200; //p->b = 200;
	//delete p;

	//Test arr[3];
	//Test* p;
	//p = arr;
	//printf("arr=%d &arr[0]=%d\n", arr, &arr[0]);
	//arr[0].a = 10;
	//arr[0].b = 20;
	//arr[1].a = 100;
	//arr[1].b = 200;
	//arr[2].a = 1000;
	//arr[2].b = 2000;
	//p->a = 11;
	//p->b = 22;
	//p++;
	//p->a = 11;
	//p->b = 22;

	/*
	//struct Test tt; typeof struct test Test
	Test tt;
	Test* p;
	p = &tt;
	printf("%d\n", sizeof(tt));
	tt.a = 10;
	tt.b = 20;
	(*p).a = 100; // p->a = 100;
	(*p).b = 200; // p->b = 200;
	cout << "tt.a=" << tt.a << endl;
	cout << "tt.b=" << tt.b << endl;
	*/
	return 0;
}