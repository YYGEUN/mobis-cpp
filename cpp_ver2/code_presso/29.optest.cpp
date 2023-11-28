#include <iostream>
#include <string>
using namespace std;

/*
반환형 operator연산자(매개 변수 목록)
{
	....// 연산 수행
}
*/

class Test {
private:
	int a; int b;
public:
	
	Test() {
		this->a = 0; this->b = 0;
		cout << "constructor call" << endl;
	}
	Test(int x, int y) {
		a = x; b = y;
		cout << "arg constructor call" << endl;
	}
	~Test() { cout << "dest call" << endl; }
	void setData(int x, int y) {
		a = x; b = y;
	}
	void show() { cout << "a=" << a << " b=" << b << endl; }

	// 일반적 연산자 오버로딩 (멤버함수:인자갯수 1개 , 일반함수 2개) 
	// 보통 밸류는 많이 보내지않음 --> 포인터,레퍼런스 활용 필요
	// operator+(Test* this,const Test&n) Test* this가 항상 포함 --> obj1 + obj2 == obj1.operator(obj2)
	Test operator+(Test& t) {
		Test newT;
		newT.a = a + t.a;
		newT.b = b + t.b;
		return newT;

		//return Test(a+t.a,b+t.b); // 권장
	}
	//Test operator+(Test t) { // 밸류로 보내는것은 주로 사용되지않는다
	//	cout << "ope +" << endl;
	//	t.a = a + t.a;
	//	t.b = b + t.b;
	//	return t;
	//}
	Test& operator=(const Test& t) { // 복사생성자는 컴파일러가 만들어줌 - (안만들어도됨)
		cout << "ope ==" << endl;
		a = t.a;
		b = t.b;
		return *this;
	}
	int operator-(int n) {
		cout << "ope -" << endl;
		return a - n;
	}

	bool operator>(int n) {
		return a > n;
	}
	bool operator==(const Test& t) {
		return a==t.a && b==t.b;
	}

};
int main() {

	bool rst;
	Test obj(15, 20);
	Test obj1(10, 20);
	rst = obj > 100; // obj.operator>(3)
	cout << rst << endl;

	if (obj == obj1) {
		cout << "같다" << endl;
	}
	else {
		cout << "다르다" << endl;
	}

	/*
	int rst;
	Test obj;
	obj.setData(10, 20);
	rst = obj - 100; // obj.operator-(100)

	cout << rst <<endl;

	//테스트
	Test obj1(10, 20);
	Test obj2(100, 200);
	Test obj3;

	obj3 = obj1 + obj2;

	obj1.show(); // 10 , 20
	obj2.show(); // 100 , 200
	obj3.show(); // 110 , 220
	*/

	Test obj2(100, 200);
	Test obj3;
	Test obj4;
	obj3 = obj1 + obj2; 
	obj3.show();
	obj1.show();
	//obj4 = obj2;
	obj4.show(); // 110 , 220

	return 0;
}