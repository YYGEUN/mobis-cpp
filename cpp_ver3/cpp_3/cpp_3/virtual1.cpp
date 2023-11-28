#include <iostream>
using namespace std;

class Animal
{
public:
	void cry1() { cout << "Animal cry" << endl; }
	virtual void cry2() { cout << "Animal cry" << endl; }
};

class Dog
	:public Animal
{
public:
	// override
	void cry1() { cout << "Dog cry" << endl; }
	virtual void cry2() override { cout << "Dog cry" << endl; }
	// override �������� üũ ���� (���Ŭ������ �����Լ��� ����� �޴���)
	// virtual�� �����ǰ� �־��
};

int main()
{
	Animal a;
	a.cry1();
	Dog d;
	d.cry1();

	Animal* p = &d;
	
	// if(����ڰ��Է��Ѱ� == 1) p=&a;

	p->cry1();
	p->cry2();

	// p->cry1() �� ��Լ��� ����ɱ�
	// �Լ� ���ε� (binding)

	// static = �����Ͻ� , dynamic = �����
	// 1.static binding;
	// --> �����Ϸ��� �����Ͻð��� �Լ� ȣ���� ����
	// --> �����Ϸ��� p�� ����Ű�� ��ü�� �����ü���� �� ���� pŸ���� Animal
	// --> ���� �����Ϸ��� �����ϴ� Animal cry1 ȣ��
	// ------------> ������������, ����ӵ� ����
	// c++, c#
	// 
	// 2.dynamic binding;
	// --> �����Ͻ� p�� ����Ű�� �޸𸮸� �����ϴ� ���� �ڵ� ����
	// --> �����ҋ� p �� ����Ű�� �޸𸮸� ������ �Լ� ����
	// --> ������ p�� Dog�� ����Ű�Ƿ� Dog cry1 ȣ��
	// ------------> ���� , ����ӵ� ����
	// java, objective-c, kotlin, python

	// c++ �� �� binding�� �����Ҽ��ִ�(virtual function) ���������� default�� static�ε�
}