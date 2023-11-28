#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
using namespace std;

class gugu {
public:
	void gugudan()
	{
		for (int n = 1; n <= 9; n++) {
			for (int m = 1; m <= 9; m++) {
				show(n, m);
			}
			cout << endl;
		}
	}
	virtual void show(int a, int b) {}
};

class AA :public gugu {
public:
	virtual void show(int a, int b) {
		printf("%2d x %2d = %2d\n", a, b, a * b);
	}
};

class BB :public gugu {
public:
	virtual void show(int a, int b) {
		printf("%2d x %2d = %2d  ", a, b, a * b);
	}
};

class CC :public gugu {
public:
	virtual void show(int a, int b) {
		if (a == 1 || a == 4 || a == 7) {
			printf("%2d x %2d = %2d %2d x %2d = %2d %2d x %2d = %2d\n",
				a, b, a * b, (a + 1), b, (a + 1) * b, (a + 2), b, (a + 2) * b);
		}
	}
};

class contxt {
private:
	gugu* pManager;
public:
	contxt() : pManager(0) {}
	~contxt() { if (pManager) delete pManager; }
	void select() {
		pManager->gugudan();
	}
	void change(gugu* _interface) {
		if (pManager) delete pManager;
		pManager = _interface;
	}
};


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	contxt* gugudan1 = new contxt;
	//gugudan1->change(new AA);
	//gugudan1->select();
	//gugudan1->change(new BB);
	//gugudan1->select();
	gugudan1->change(new CC);
	gugudan1->select();

	delete gugudan1;

	return 0;
}