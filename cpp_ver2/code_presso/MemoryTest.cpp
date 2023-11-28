#include <stdio.h>
#include <iostream>
using namespace std;


int rValue() {
	int n = 100;
	return n;
}

int Fn() {
	int n = 100;
//	return n;
	__asm {
		mov eax, n;
	}
}

int main()
{
	int rst;
	//rst = rValue();
	Fn();
	__asm {
		mov rst, eax;
	}

	cout << "rst=" << rst << endl;
	return 0;
}

//void callByValue(int n){
//	n = 100;
//}
//void callByPointer(int* p) {
//	*p = 100;
//}
//void callByRef(int& r) {
//	r = 100;
//}
//int main()
//{
//	int a = 10;
//	//callByValue(a);
//	//callByPointer(&a);
//	callByRef(a);
//	cout << "a=" << a << endl;
//
//	/*
//	int a = 10;
//	int& r = a;
//	//int& r;
//	//r = a;
//	r = 100;
//	cout << "a=" << a << endl;
//	cout << "r=" << r << endl;
//	printf("a林家:%d r林家:%d\n", &a, &r);
//	*/
//	return 0;
//}

//
//int main()
//{
//	//char c[4] = { 'a','b','c' ,0};
//	char c[4] = "abc";
//	c[0] = 'A';
//	//string area:橇肺弊伐 辆丰矫 鳖瘤 蜡瘤, readonly
//	const char* s1 = "def";
//	const char* s2 = "Def";
//
//	printf("%d\n", c);
//	printf("%d\n", s1);
//	printf("%d\n", s2);
//
//	//*s1 = 'A'; s[0] = 'A'; X
//	printf("%c %c\n", *s1, s1[0]);
//
//	//printf("%d\n", c[0] );
//	//printf("%c\n", c[0]);
//	//printf("%s\n", c);
//
//	return 0;
//
//}
// 
// 

//int main()
//{
//		int a[3] = {10, 20, 30 };
//		int* p;
//		p = a;
//		*p = 100; //	p[0] = 100;
//		*(p+1) = 200; // p[1] = 200;
//		*(p+2) = 300; // p[2] = 300;
//		printf( "a[0]林家:%d, a[1]林家:%d, a[2]林家:%d\n", &a[0], &a[1], &a[2] );
//		// p, p+1, p+2
//		printf( "a:%d\n", a);
//		printf( "p:%d\n", p);
//		printf( "a[0]:%d, a[1]:%d, a[2]:%d\n", a[0], a[1], a[2] );
//		// p[0], p[1], p[2], *p, *(p+1), *(p+2)
//	return 0;
//}
// 
//
//int main() {
//	int a = 0;
//	int* p;
//	p = &a;
//	*p = 100;
//
//	double d = 3.14;
//	double* dp;
//	dp = &d;
//	//p = (int*)&d;
//	//p = static_cast<int*>(&d);
//	//*p = 5.6;
//	*dp = 5.6;
//
//	double  f = 3.14;
//	int num = static_cast<int>(f); // (int)f c stype
//
//	printf("p=%d, a林家:%d\n", p, &a);
//	printf("dp=%d, d林家:%d\n", dp, &d);
//
//	return 0;
//}
//

//int g;
//void fn() {
//	int a = 0;
//	static int b = 0;
//	printf("a=%d b=%d\n", a, b);
//	printf("a林家:%d\n", &a);
//	printf("b林家:%d\n", &b);
//	a++;
//	b++;
//}
//int main() {
//	printf("g林家:%d\n", &g);
//	fn();
//	fn();
//	fn();
//
//	return 0;
//}

//
//int g;
//void Fn1() {
//	int a;
//	int b;
//}
//void Fn() {
//	int n;
//	Fn1();
//}
//
//int main() {
//	int x;
//	int y;
//	Fn();
//	printf("Fn林家:%d\n", Fn);
//	printf("x林家:%d\n", &x);
//	printf("y林家:%d\n", &y);
//	printf("g林家:%d\n", &g);
//
//	return 0;
//}