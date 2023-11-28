#include <iostream>
#include <cstring>
using namespace std;

//void gugudanH()
//{
//	for (int n = 1; n <= 9; n++) {
//		for (int m = 1; m <= 9; m++) {
//			printf("%2dx%2d=%2d\n", n, m, n * m);
//		}
//	}
//}
//void gugudanV()
//{
//	for (int n = 1; n <= 9; n++) {
//		for (int m = 1; m <= 9; m++) {
//			printf("%2dx%2d=%2d ", n, m, n * m);
//		}
//		printf("\n");
//	}
//}

class Gugudan {
public:
	void procgugudan() {
		for (int n = 1; n <= 9; n++) {
			for (int m = 1; m <= 9; m++) {
				show(n, m);
			}
			printf("\n");
		}
	}

	virtual void show(int a, int b) = 0;
};
class GugudanM :public Gugudan {
public:
	void show(int a, int b) {
		if (a % 3 == 1) {
			printf("%2dx%2d=%2d , %2dx%2d=%2d  , %2dx%2d=%2d \n", a, b, a * b, a + 1, b, (a + 1) * b, a + 2, b, (a + 2) * b);
		}
	}
};

class GugudanV :public Gugudan {
public:
	void show(int a, int b) {
		printf("%2dx%2d=%2d ", a, b, a * b);
	}
};
class GugudanH :public Gugudan {
public:
	void show(int a, int b) {
		printf("%2dx%2d=%2d\n", a, b, a * b);
	}
};

int main() {
	//gugudanH();
	//Gugudan* pgugudan = new GugudanV();
	Gugudan* pgugudan = new GugudanM();
	pgugudan->procgugudan();

	delete pgugudan;

	return 0;
}

// 10분 퀴즈 전략패턴