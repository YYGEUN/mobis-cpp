#include <stdio.h>
#include <iostream>
#define PI 3.14
#define SQRT(X) ((X)*(X))
using namespace std;

inline int sqrt(int x) {
	return x * x;
}

int main(){
	double d = PI;// double d = 3.14
	//PI = 5.6; // 3.14 = 5.6
	int n = 2;
	int rst;
	//rst = SQRT(3); // 3*3
	//rst = SQRT(n + 2); //(n + 2) * (n + 2)
	//rst = 10 / SQRT(n + 2); // 10/((n+2)*(n+2))
	rst = sqrt(3); // 3*3
	return 0;
}