#include <iostream>
#include <initializer_list>

using namespace std;

//templete
template<typename t1, typename t2>
auto Plus(t1 t, t2 tt) -> decltype(t + tt)
{
	return t + tt;
}

template<typename t1, typename t2>
auto Minus(t1 t, t2 tt) -> decltype(t - tt)
{
	return t - tt;
}

//inline 함수
//즉시 연산함수 (간단한 연산에 이용)
//함수 호출 -> 스택구조
//어떤 연산을 담당하는 함수가 존재한다가정 --> 함수의 호출 구조상 스택이 발생하게되어 연산의 병목현상발생
//인라인함수 호출시 즉시 연산으로 해결
//일반 함수도 모두 묵시적으로 iline 임

//컴파일시 매개변수 추론이 불가능해서 컴파일에러
//void outa(auto b) .....

//가능은하나 서로다른 매개변수의 합이나 계산결과를 auto 로 받는것은 안좋음
auto testa(int a, float b) {
	return a + b;
}

//후행반환형식
auto output1() -> double {
	return 3.33f;
}

struct sta {
	int a;
	int b;
};

int Accel(int i) {
	return i + 1;
}

int main() {
	// auto
	// 타입추론을 자동으로 해줌
	// 함수형도 받을수있다

	auto io1 = output1;

	cout << io1() << endl;

	auto a = 8;
	auto c = "asda";
	auto& num = a;

	cout << num << endl;

	a = 5;

	cout << num << endl;

	//auto가 추론 불가능함
	//auto numb = { 7,2.3f };


	//람다식 -- 익명함수
	auto lambdatest = [] {
		cout << "dddasd\n";
		};
	auto lambdatest2 = [](int a) {
		cout << a * 7 <<endl;
		};

	lambdatest();
	lambdatest2(3);


	sta* abc = new sta;
	abc->a = 1;
	abc->b = 2;

	auto bbc = abc;
	bbc->a = 77;
	bbc->b = 5;

	cout << abc->a << endl;
	
	string s1 = "sweet";
	string s2 = "home";

	cout << Plus(s1, s2) << endl;
	cout << Minus(3, -5) << endl;


	//범위기반 반복문
	int arr[5] = { 1,2,3 };
	for (int i : arr) {
		cout << i << endl;
	}

	if (int want = Accel(50); want <= 60) {
		cout << "ok" << endl;
	}

	

	return 0;
}