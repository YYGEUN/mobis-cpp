#pragma once
#include <iostream>

using namespace std;
//.h 헤더
//.cpp 헤더에 종속

class MainClass
{
	//private - 객체자신만 접근가능 (defalut 값) ** 구조체는 defalut가 public
	//protected - 상속관계만 접근가능
	//public - 외부접근 가능
	//접근제한 지시자는 여러개 사용할수있다.

private:
	float _guage; /// private 함수이므로 같은 클래스 내에서만 사용가능
	int _PLevel;

public:
	//float _guage; /// 밖의 예를들면 main.cpp에서 구조체처럼 접근가능하다
	//int _num;
	//defalut 값으로 생성자 소멸자를 생성하지않아도 있음 (추가로 선언해서 사용할수도있다)

	MainClass(); // 생성자 - 객체가 생성되면 자동호출 -- 중복생성가능
	MainClass(int n);
	MainClass(int n,float guage);

	void Init(); // main_init 처럼 각개의 cpp 파일에 연결하여 정의가능 --> 가시성확보(볼떄 복잡도 낮춤)
	void Release();
	void Update();

	//echo(int);
	~MainClass(); // 소멸자 - 객체 소멸시 자동호출 -- 중복생성 불가 단일!
};
