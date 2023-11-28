#include <iostream>
#include <string>
using namespace std;

/*
��ȯ�� operator������(�Ű� ���� ���)
{
	....// ���� ����
}
*/

class Test {
private:
	int a; int b;
public:
	
	Test() {
		this->a = 0; this->b = 0;
		cout << "constructor call" << endl;
	}
	Test(int x, int y) {
		a = x; b = y;
		cout << "arg constructor call" << endl;
	}
	~Test() { cout << "dest call" << endl; }
	void setData(int x, int y) {
		a = x; b = y;
	}
	void show() { cout << "a=" << a << " b=" << b << endl; }

	// �Ϲ��� ������ �����ε� (����Լ�:���ڰ��� 1�� , �Ϲ��Լ� 2��) 
	// ���� ����� ���� ���������� --> ������,���۷��� Ȱ�� �ʿ�
	// operator+(Test* this,const Test&n) Test* this�� �׻� ���� --> obj1 + obj2 == obj1.operator(obj2)
	Test operator+(Test& t) {
		Test newT;
		newT.a = a + t.a;
		newT.b = b + t.b;
		return newT;

		//return Test(a+t.a,b+t.b); // ����
	}
	//Test operator+(Test t) { // ����� �����°��� �ַ� �������ʴ´�
	//	cout << "ope +" << endl;
	//	t.a = a + t.a;
	//	t.b = b + t.b;
	//	return t;
	//}
	Test& operator=(const Test& t) { // ��������ڴ� �����Ϸ��� ������� - (�ȸ�����)
		cout << "ope ==" << endl;
		a = t.a;
		b = t.b;
		return *this;
	}
	int operator-(int n) {
		cout << "ope -" << endl;
		return a - n;
	}

	bool operator>(int n) {
		return a > n;
	}
	bool operator==(const Test& t) {
		return a==t.a && b==t.b;
	}

};
int main() {

	bool rst;
	Test obj(15, 20);
	Test obj1(10, 20);
	rst = obj > 100; // obj.operator>(3)
	cout << rst << endl;

	if (obj == obj1) {
		cout << "����" << endl;
	}
	else {
		cout << "�ٸ���" << endl;
	}

	/*
	int rst;
	Test obj;
	obj.setData(10, 20);
	rst = obj - 100; // obj.operator-(100)

	cout << rst <<endl;

	//�׽�Ʈ
	Test obj1(10, 20);
	Test obj2(100, 200);
	Test obj3;

	obj3 = obj1 + obj2;

	obj1.show(); // 10 , 20
	obj2.show(); // 100 , 200
	obj3.show(); // 110 , 220
	*/

	Test obj2(100, 200);
	Test obj3;
	Test obj4;
	obj3 = obj1 + obj2; 
	obj3.show();
	obj1.show();
	//obj4 = obj2;
	obj4.show(); // 110 , 220

	return 0;
}