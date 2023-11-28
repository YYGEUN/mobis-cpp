#include <iostream>

using namespace std;

int main() {

	const char* a = "aaaaa";
	int num;

	while (1) {
		cin >> num;
		//변수 자료형에 맞지않는입력값일떄 오버플로우현상 예외처리
		if (cin.fail() == true) {
			//입력된 오류값 우선 초기화
			cin.clear();
			//입력된 버퍼값을 취소 --> 계행문자를 만날때 까지
			cin.ignore(10, '\n'); // == cin.ignore()
		}
		cout << num << "\n";
	}


	return 0;
}