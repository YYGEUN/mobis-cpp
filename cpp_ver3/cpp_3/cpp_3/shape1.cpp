#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
	virtual ~Animal(){} // ��ӽ� ����� Ŭ�����Ҹ��ڴ� �ݵ�� �����Լ�
						// ��� Ŭ���� --> ���� �Ҹ��� �ʼ�
};

class Dog
	:public Animal
{
public:
	int color;
};

int main()
{
	Dog dog;
	Dog* p1 = &dog;
	//int* p2 = &dog; // �����ٸ�Ÿ��
	Animal* p3 = &dog; // upcasting

	// �ٽ�1. �Ļ� Ŭ���� ��ü�� �ּҸ� ��� Ŭ���� �����Ϳ� �������ִ� 
	// upcasting

	// �ٽ�2. ��� Ŭ���� �����ͷδ� ���Ŭ���� ����� ���ٰ���
	//		ex) �����Ϸ� ���忡�� p3�� Animal�̶�� ����
	p3->age = 10;
	//p3->color = 1; // error

	// �ٽ�3. p3�� Dog ���� ����� �����Ϸ��� �ٿ�ĳ����
	// �� �̰�� p3�� ����Ű�°��� �ݵ�� Dog��� Ȯ���ʿ�
	// Dog ��ü�� �ƴϸ� "�߸��� �޸� ����" �߻�
	static_cast<Dog*>(p3)->color = 10;

	// �ٽ�4. ���� ���簡�ʿ��ߴٸ� dynamic_cast�� ����ϴ� ���������
	Animal a;
	Animal* p4 = &a;

	// p4�� Dog���ƴ� Animal ��ü�� ����Ŵ

	//Dog* pdog = static_cast<Dog*>(p4);  // ���������� pdog ���� ������ �߻��Ҽ�����
	//									// --> staic_cast�� �����Ͻ� ����ȴ�


	// p4�� ����Ű�� ���� Dog���� ������ ĳ���� --> ������ ĳ����, Ʋ���� 0
	Dog* pdog = dynamic_cast<Dog*>(p4); // �����Լ��� �ϳ��̻��־�� ��밡��

	cout << p1 << endl;
	cout << p4 << endl;
	cout << pdog << endl;
}