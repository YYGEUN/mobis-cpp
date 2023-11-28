#include <iostream>
#include <string>
#include <map>
using namespace std;
using FunctionType = void (*)(int);
// void (*fn)(int)
//clean code:
// 명명규칙:영어단어
// if문 
//적은 라인...
void fn1(int n) {

	cout << "fn1 call" << n << endl;
}
void fn2(int n) {
	cout << "fn2 call" << n << endl;
}
int main()
{
	map<string, int> mymap;
	mymap["aa"] = 100;
	mymap["bb"] = 200;
	cout << mymap["aa"] << endl;

	//map<int, FunctionType> fnMap; //map<int, void (*)(int)> fnMap;
	//fnMap[1] = fn1;
	//fnMap[2] = fn2;
	map<int, FunctionType> fnMap{ {1,fn1},{2,fn2} };
	fnMap[1](100);
	fnMap[2](200);

	return 0;
}