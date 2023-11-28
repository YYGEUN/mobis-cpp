#include <iostream>

//using -> type,templete 적용가능
// ex) using DWORD = int;
// ex) using callbackF = void(*)(void*);
//typedef -> type만 가능
// typedef void(*callbackF)(void*);
// typedef const char* ObjectName;

typedef struct abc {
	int a;
}ABC,*PABC;

using namespace std;



// 코드작성시 변수명,함수명 중복사용하고싶을때
// 원칙은 중복사용 불가 --> namespace 지정시 해결가능
// 협업시 코드작성중의 변수명,함수명 충돌을 방지가능

namespace engine
{
	double temp = 25;
	void output() {
		cout << "엔진 온도 : " << temp << endl;
	}
}

namespace incar
{
	double temp = 25;
	void output() {
		cout << "차내 온도 : " << temp << endl;
	}
}

namespace calculate {
	int getdis(float a1, float b1, float a2, float b2)
	{
		float dist;
		dist = sqrt(pow((a1 - b1), 2) + pow((a2 - b2), 2));
		return dist;
	}
}

int main() {
	// :: 범위지정 연산자 
	// 클래스에도많이사용 
	// 호출한 함수,변수가 누구의것인지 명시

	int num(3); // == int num{3})({} 의경우 엄격한선언 규칙-- 형변환이 맞아야함) 선언문에서 만 딱한번 사용가능 int num = 3과 같음
	int arr[3]{ 1,2,3 }; // 배열도 가능

	engine::temp = 45.0;
	incar::temp = 22.0;

	engine::output();
	incar::output();

	//int aa{3.3f}; // 불가
	int aa(3.3f); // 가능 하지만 float 손실

	//char c('a');
	char c{ 97 };

	cout << c << endl;


	int money = 1'000'000; // 자르는 표현가능
	int cc = 0x00b;

	cout << money << endl;

	cout <<  << endl;
	return 0;
}