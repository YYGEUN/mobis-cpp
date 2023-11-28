#include <iostream>
#include <cstring>
using namespace std;

// 단일 객체 (singletone)
// 1.하나의 객체
// 2.자신의클래스를 has-a
// 3.private 생성자로 런타임객체 생성을 금지


class SingleTone {
private:
	int x, y;
	static SingleTone instance; // 사이즈를 모르므로 스태틱 필수지정필요
	SingleTone() { cout << "const call " << endl; x = 0;  y = 0; }
public:
	static SingleTone& getins() {
		return instance;
	}
	void setData(int a, int b) { x = a; y = b; }
	void show() {
		cout << "x = " << x << " y = " << y << endl;
	}
};

SingleTone SingleTone::instance;
int main() {
	SingleTone& stone = SingleTone::getins();
	stone.setData(100, 200);
	//SingleTone stone1; // 불가능 --> 생성자가 프라이빗이기때문에 새로운 객체 생성 불가
	SingleTone* pstone;
	pstone->setData(22, 22);

	//SingleTone* pstone = new SingleTone; // 불가능 --> 재생성 불가능 이유는 위와 같다

	return 0;
}
