#include <iostream>

using namespace std;

// c++

// 오버로드

// 1. 함수명 중복 허용
//	--> 함수오버로드
// 함수 구성요소,형태가 달라야함
// 반환형만 다른함수 오버로드 불가

//call by value --> 원본 보존
//call by pointer --> 값변경가능, 복사과정이없어 빠름(value는 임시값에 복사후 재복사가 이뤄짐)

void output() {
	cout << "출력\n";
}

void output(int num = NULL) { // num 값을 미리 초기화하는것도 가능
	cout << "입력받은값 :" << num << endl;
}

void output(float num) {
	cout << "입력받은값 :" << num << endl;
}

void swap1(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap2(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int& makeNum() {
	int num = 7;

	return num;
	//return 과 동시에 num은 지역변수로서 소멸됨
}

int main() {

	int a = 8;
	// b는 a의 변수가 할당 받은 주소값을 그대로가짐
	int& b = a;
	// c는 a가 할당 받은메모리주소를 가리킴
	int* c = &a;

	cout << &a << endl;
	cout << &b << endl;
	cout << c << endl;

	int num1 = 1;
	int num2 = 2;

	swap1(num1, num2);

	cout << num1 << "   " << num2 << endl;

	swap2(&num1, &num2);

	cout << num1 << "   " << num2 << endl;

	// 상수 참조
	const int n = 111;

	//불가능한 예제) 상수참조자는 비상수 참조자를 참조 불가
	//int& ref = n;
	//가능 예제)
	const int& refn = n;
	const int& refnn = 100;
	//위 형식은 100이라는 임시값을 대입했다가 다음행에서 소멸  (임시 로 100을 복사하여 저장하고 refnn에 넣고 소멸)


	//& ref 사용시 주의
	int& ran = makeNum();
	//지역변수는 함수가 끝나면서 메모리소멸 --> 소멸된 메모리 참조시 참조에러
	//Dangling REF 현상 이라고함 (해제된 메모리를 참조하는 연산자)

	int& np = a;

	//1.배열타입
	//2.const 타입
	//3.불완전타입

	return 0;
}