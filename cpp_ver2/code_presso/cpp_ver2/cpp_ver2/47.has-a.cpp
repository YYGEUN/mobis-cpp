#include <iostream>
#include <cstring>

using namespace std;

// 스태틱 -------------------------
class A {
	int a, b;
public:
	void setab(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void show() {
		cout << "a = " << a << "b = " << b << endl;
	}
};

class B {
	int x, y;
	static int st;
	static A sa;
	static A* psa;
public:

	B() {}
	~B() { delete psa; }

	static A a;
	static A& getsa() {
		return sa;
	}
	static A* getpsa() {
		return psa;
	}
	void setxy(int a, int b) {
		this->x = a;
		this->y = b;
	}
};

A B::a;
A* B::psa = new A;
int B::st = 100;

/// 클래스 -------------------------
//class A {
//	int a, b;
//public:
//	void setab(int a, int b) {
//		this->a = a;
//		this->b = b;
//	}
//	void show() {
//		cout << "a = " << a << "b = " << b << endl;
//	}
//};
//class B {
//	int x, y;
//	A pria;
//	A* pripa;
//public:
//	A a;
//	A* pa;
//	A& geta() {
//		return pria;
//	}
//	A* getpa() {
//		return pripa;
//	}
//
//	B() { pa = new A; }
//	~B() { delete pa; }
//
//	void setxy(int a, int b) {
//		this->x = a;
//		this->y = b;
//	}
//};

/// 스트럭트 -------------------------
//struct A {
//	int a, b;
//};
//struct B {
//	int x, y;
//	//A aa; // has-a
//	A* pa;
//};

int main() {


	// ---------------- 스트럭트
	//B b;
	//b.x = 10;
	//b.y = 12;
	//b.pa = new A;
	//b.pa->a = 23;
	//b.pa->b = 35;

	//delete(b.pa);

	//B* pb;
	//pb = new B;
	//pb->y = 73;
	//pb->pa = new A;
	//pb->pa->a = 37;
	// 
	//delete pb->pa;
	//delete pb;

	// ------------------- 클래스
	//class B b;
	//b.setxy(10, 10);
	//b.a.setab(7, 7);
	//b.a.show();

	//b.geta().setab(17, 923);
	//b.geta().show();

	////b.pa = new A;
	//b.pa->setab(23, 12);
	//b.pa->show();

	//b.getpa()->setab(231, 23);

	//B* pb; // 제일 많은 케이스 ===
	//pb->setxy(3, 3);
	//pb->pa->setab(7, 7);
	//delete pb;

	/// -------------------------스태틱
	B::a.setab(3, 2);
	B::getsa().setab(3, 8);
	B::getpsa()->setab(9, 1);

	return 0;
}
