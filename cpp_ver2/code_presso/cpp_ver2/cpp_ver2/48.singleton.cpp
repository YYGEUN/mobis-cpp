#include <iostream>
#include <cstring>
using namespace std;

// ���� ��ü (singletone)
// 1.�ϳ��� ��ü
// 2.�ڽ���Ŭ������ has-a
// 3.private �����ڷ� ��Ÿ�Ӱ�ü ������ ����


class SingleTone {
private:
	int x, y;
	static SingleTone instance; // ����� �𸣹Ƿ� ����ƽ �ʼ������ʿ�
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
	//SingleTone stone1; // �Ұ��� --> �����ڰ� �����̺��̱⶧���� ���ο� ��ü ���� �Ұ�
	SingleTone* pstone;
	pstone->setData(22, 22);

	//SingleTone* pstone = new SingleTone; // �Ұ��� --> ����� �Ұ��� ������ ���� ����

	return 0;
}
