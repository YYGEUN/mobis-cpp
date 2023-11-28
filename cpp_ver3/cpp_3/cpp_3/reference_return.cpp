#include <iostream>
using namespace std;

int f1(int a) { return a; } // a의 값을 반환하는 코드
int& f2(int a) { return a; } // a의 레퍼런스를 반환하는 코드 (a의 별명을 반환하는것과 같다)

int main()
{
	// 일반적으로 함수호출을 우변
	int ret = f1(5);
	
	// 함수호출이 좌변에 놓인는 경우가있음
	// ex) v[0] = 10; == v.operator[](0) = 10;
	// --->
	//f1(7) = 10; // int에 int를 할당할수가없음 7 = 10
	f2(8) = 10; // 
	cout << (f2(8)=10) << endl;
	cout << f2(8) << endl;
 	return 0;
}