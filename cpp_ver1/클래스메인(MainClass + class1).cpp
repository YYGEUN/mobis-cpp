#include <iostream>
#include "MainClass.h"
#include "Class1.h"

using namespace std;

int main() {
	//MainClass MC(7);// 스택구조로 열림
	//MainClass MC2(3,3.14);

	////cout << MC._num << endl;
	////cout << MC2._num << endl;

	Class1 C1;
	Class1 C2;
	
	//C1.Plus(4).Minus(5).Print();

	C1.Minus(5)->Plus(6)->Minus(7)->Print();
	__number += 5;
	C2.Print();


	return 1;
}