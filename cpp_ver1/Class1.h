#pragma once
#include <iostream>

using namespace std;

// static은 전역변수에서 선언해주자
// static이 있을때는 여러함수에서 참조시 값처리 주의
static int __number = 0;


class Class1
{
private:
	int num;
	int result = 0;

public:
	//Class1();
	//~Class1();

	//객체의 멤버함수를 호출할떄 컴파일러가 각멤버함수 앞에 해당객체이름을 명시해서 변환후 호출
	// 객체 내부에 멤버변수, 함수앞에는 this->가 묵시적으로 붙음

	void InPutNum(int num) {
		this->num = num; 
		// this는 현재 클래스를 지칭하는 포인터
		// 매개변수명과 클래스의 멤버변수이 겹칠수있을때 한번더 명시적으로 표기해주는것
	}

	void Print() { cout << __number << endl; }

	//Class1& Plus(int value) { result += value; return *this;}
	//Class1& Minus(int value) { result -= value; return *this; }
	//Class1& Times(int value) { result *= value; return *this; }

	Class1* Plus(int value) { __number += value; return this; }
	Class1* Minus(int value) { __number -= value; return this; }
	Class1* Times(int value) { __number *= value; return this; }

};

