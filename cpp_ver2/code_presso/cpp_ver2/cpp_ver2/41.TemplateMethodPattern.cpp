#include <iostream>
#include <cstring>
using namespace std;

class ��
{
public:
	void ���´�()
	{
		cout << "���� ���´�" << endl;
	}
	void �丮����()
	{
		��÷�����ֱ�(); // ��ȭ�Ǵ� �κи� �ٲܼ��ֵ���
		���´�();
	}
	virtual void ��÷�����ֱ�() = 0;
};

class ��ġ������ : public ��
{
public:
	virtual void ��÷�����ֱ�()
	{
		cout << "��ġ�� �ִ´�" << endl;
	}
};
class ���캺���� : public ��
{
public:
	virtual void ��÷�����ֱ�()
	{
		cout << "���츦 �ִ´�" << endl;
	}
};

class ��ä������ : public ��
{
public:
	virtual void ��÷�����ֱ�()
	{
		cout << "��ä�� �ִ´�" << endl;
	}
};

int  main()
{
	��* p_rice = new ��ġ������;
	p_rice->�丮����();
	return 0;
}
