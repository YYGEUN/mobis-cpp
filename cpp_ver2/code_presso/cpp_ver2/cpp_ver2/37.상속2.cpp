#include <iostream>

using namespace std;

class Father {
	int priVal;
protected:
	int proVal;
public:
	int pubVal;
	Father() {
		cout << "Father const call" << endl;
		priVal = 0;
		proVal = 0;
		pubVal = 0;
	}
	~Father() { cout << "Father dest call" << endl; }
	void setpri() {
		priVal = 33;
	}
};

class child
	:public Father
{
public:
	int chVal;
	child() {
		cout << "child const call" << endl;
		chVal = 0;
	}
	~child() {
		cout << "child dest call" << endl;
	}
	void pubfn() { cout << "��ӵ�" << endl; }
	void profn() {
		cout << proVal << endl;
	}
};

class baby
	:public child // protected child �� ������ public�� protected�� �޾�����--> ����ȣ�� �Ұ�, ���������� �̿밡��
	// private childe �� ��� ������ ���� private�� �ǰ� �߰��� �ٸ� �Լ����� ��� �ޱ��ƴ�
// public : private ���� ����� ���ٱ��� �״�� ���
// protected : protected ���ٱ����ڷ� ��� (public--> protected ȭ)
//private : private ���ٱ����ڷ� ��� 
{
public:
	int babyVal;
	baby() {
		cout << "baby const call" << endl;
		babyVal = 0;
	}
	~baby() {
		cout << "baby dest call" << endl;
	}

	void pro_babyfn() {
		proVal = 77;
	}
};

int main() {
	baby by;
	by.pro_babyfn();
	by.babyVal = 5;
	by.chVal = 25;
	by.pubVal = 125;
	by.setpri();
	return 0;
}