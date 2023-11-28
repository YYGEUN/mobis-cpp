#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base(){} // ��� Ŭ������ ����Ǵ� Ŭ������ �ݵ�� ����Ҹ��� ����
};

class Derived
	:public Base
{
public:
	Derived() { cout << "�޸��Ҵ�\n"; };
	~Derived() { cout << "�޸�����\n"; };

};

int main()
{
	Derived d;
	Derived* pd = new Derived;
					//1. ���� �޸� �Ҵ�
					//2. ������ ȣ��

	delete pd;
					//1. �Ҹ��� ȣ��
					//2. �޸� ����

	Base* bpd = new Derived;

	delete bpd;
					// �Ҹ��ڸ� ȣ���ؾ��ϴµ� �Ҹ��� ȣ�⵵ �Լ�ȣ���̴�.
					// static binding, dynamic binding �����ؾ���
					// 1. �����Ϸ��� p�� Base* ��� �͸� �˰� ����
					// 2. �׷��� Base���𿡼� �Ҹ��ڰ� �����Լ����� ����
					//		--> �ƴϸ� �����Ϸ��� ���� (�����Լ��� �ƴ� �Ҹ���)

					// �����̾ƴϸ� delete bpd �Ҷ� Base �Ҹ��ڸ� ȣ��
					// �����̸�     delete bpd �Ҷ� ����bpd�� ����Ű�� ��ü�� ������ �Ҹ��� ȣ��

	return 0;
}