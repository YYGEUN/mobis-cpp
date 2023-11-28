#include <iostream>
using namespace std;

class Test {
private:
	int a, b;
public:
	Test() {
		cout << "const call" << endl;
		this->a = 0, this->b = 0;
	}
	Test(int a, int b) { cout << "arg call" << endl;
	this->a = a, this->b = b;
	}
	~Test() { cout << "dest call" << endl; }
	void SetData(int a, int b) { this->a = a, this->b = b; }
	void Show() { cout << "a = " << a << "b = " << b << endl; }
	friend void Fn();
	
	int operator+(int n) { return a + n; }
	friend int operator+(int n, const Test& t);
};

// 2�� �������� ��� 
// ����Լ� �����ε� : ���� 1��
// �Ϲ��Լ� �����ε� : ���� 2��

int operator+(int n, const Test& t) {
	return n + t.a;
}

void Fn() {
	Test t;
	t.a = 10;
	t.b = 20;
}

int main() {
	//Fn();
	Test obj(10, 20);
	int rst;
	rst = obj + 110;
	cout << rst << endl;
	rst = 100 + obj; // 100.operator(obj) �Ұ� --> operatior(100,obj) ����

	cout << rst << endl;

	int n = 10;


	return 0;
}