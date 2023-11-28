#include <iostream>

using namespace std;

void main() {
	//static_cast----------------------------------------------------------------------------------
	//정적 캐스팅 
	//컴파일시 형변환이 가능한지 검사후 변환을 진행 --> 불가능시 컴파일에러

	float speed = 123.123f;
	int av = 312;
	int* a = &av;
	cout << static_cast<int>(speed) << endl;

	speed = (int)speed;

	int* speedmeter = (int*)&speed; // 강제형변환이므로 바꾸고 컴파일 시킴
	//int* speedmeter = static_cast<int*>(&(speed)); //--> 형변환 가능성을(위험성) 먼저 검토하므로 불가능하면 컴파일 불가

	// 상속관계에서 포인터끼리 캐스팅을 허용

	cout << a << "     " << av << endl;
	cout << speedmeter << endl;

	//reinterpret_cast----------------------------------------------------------------------------------
	//c 캐스팅 방식과 흡사(강제형변환)
	//포인터 타입을 일반 변수타입으로도 캐스팅이 가능   포인터 <---> 일반변수 모두 가능

	int* speedmeter2 = reinterpret_cast<int*>(&(speed));

	cout << speedmeter2 << endl;

	int number = 65;
	char* cptr = reinterpret_cast<char*>(&number);

	cout << cptr << endl;

	//const_cast----------------------------------------------------------------------------------
	//상수를 무효화 해주는기능
	
	const char* str = "한성이바보";

	cout << str << endl;

	char* str2 = const_cast<char*>(str);

	cout << str2 << endl; 

	return;
}