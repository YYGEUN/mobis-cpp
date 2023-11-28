#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

// 1. 모든 멤버함수의 1번째 인자에 클래스이름* this 추가
// 2. 멤버데이터 : this->멤버데이터
// 2. 객체.멤버함수 ==> 객체.멤버함수( 객체주소 ,...)
// 3. 생성자함수 정의가 없으면 디폴트생성자 추가
class Test{
private:
	int a;
	int b;
public:
	//void setData(Test* this, int x, int y)
	void setData(int x, int y) 
	{
		a = x; //this->a = x
		b = y; //this->b = y
	}
	//void show(Test* this)
	void show() {
		cout << "a=" << a << " b=" << b << endl;
		//cout << "a=" << this->a << " b=" << this->b << endl;
	}
	//Test(){}
};
int main(){
	Test tt;
	tt.setData(100, 200); //tt.setData(&tt, 100, 200);
	tt.show(); // tt.show(&tt);

	return 0;
}