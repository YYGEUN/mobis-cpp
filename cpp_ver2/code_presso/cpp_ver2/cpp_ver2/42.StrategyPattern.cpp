#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------------------
// ���� �������̽�
class ����_�������̽�
{
public:
	virtual void ����() = 0;
};
//------------------------------------------------------------------
// �� ���� �˰��� Ŭ����
class ������ : public ����_�������̽�
{
public:
	void ����() override { cout << "�� ����" << endl; }
};
//------------------------------------------------------------------
// ���� ���� �˰��� Ŭ����
class �������� : public ����_�������̽�
{
public:
	void ����() override { cout << "���� ����" << endl; }
};
//------------------------------------------------------------------
// ���� ���� �˰��� Ŭ����
class �������� : public ����_�������̽�
{
public:
	void ����() override { cout << "���� ����" << endl; }
};

//------------------------------------------------------------------
// ���� ������ Ŭ����
class ���İ�����
{
public:
	���İ�����() : pInterface(0) {}
	~���İ�����() { if (pInterface) delete pInterface; }
public:
	void ����() { pInterface->����(); }
	void �������̽�_����(����_�������̽�* _interface)
	{
		if (pInterface) delete pInterface;
		pInterface = _interface;
	}
private:
	����_�������̽�* pInterface;
};
//------------------------------------------------------------------
// Main
int main()
{
	���İ�����* pManager = new ���İ�����();
	pManager->�������̽�_����(new ��������());
	pManager->����();
	pManager->�������̽�_����(new ������());
	pManager->����();
	pManager->�������̽�_����(new ��������());
	pManager->����();
	delete pManager;
	return 0;
}
