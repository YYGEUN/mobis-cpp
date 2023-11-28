#include <iostream>
#include <vector>
using namespace std;

// �Ŀ� ����Ʈ ���� ���α׷�

//1. ������ class�� ����

//2. ��絵���� ������ Ŭ������ �ִٸ� ��������� ������ �ϳ��� vector�� ��������

class shape
{
public:
	virtual ~shape() {}
	virtual void draw() = 0;
};

class Rect : public shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) :x(x), y(y), width(w), height(h)
	{

	}
	void draw() { cout << "draw rect" << endl; }
};

class Circle : public shape
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) :x(x), y(y), radius(r)
	{

	}
	void draw() { cout << "draw circle" << endl; }
};


int main()
{
	vector<shape*> v; // rect,circle Ŭ������ ��� �������ִ�

	while (1)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			Rect rc(0, 0, 100, 100); // {} ����� �ı�
			Rect* r1 = new Rect(0, 0, 100, 120); // �����Ҵ��ϰ�
			v.push_back(r1); // �ּҸ� ����
		}
		// rc �ı���
		else if (cmd == 2)
		{
			v.push_back(new Circle(0, 0, 17));
		}
		else if (cmd == 9)
		{
			for (auto p : v) {
				p->draw(); // ���� p��Ÿ���� shaep �̱⶧���� 
			}
		}
	}

}