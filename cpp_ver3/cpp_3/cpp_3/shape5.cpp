#include <iostream>
#include <vector>

#define PI 3.14;

using namespace std;

// �Ŀ� ����Ʈ ���� ���α׷�

//1. ������ class�� ����

//2. ��絵���� ������ Ŭ������ �ִٸ� ��������� ������ �ϳ��� vector�� ��������

//3. ��� ������ ���� Ư���� �ݵ�� ���Ŭ�����κ��� �����Ǿ���� ex) draw
//	 Shape*�� �ش�Ư���� ����ϱ�����
//	 �������̾ƴ� ������ ������ ��Ģ

//4. ���Ŭ������ ���� ����Լ��� �Ļ�Ŭ������ override�ϴ� ���� �ݵ�� �����Լ�

class shape
{
protected:
	int color;
public:
	virtual ~shape() {}

	void set_color(int c) { color = c; } // �ڽ�Ŭ������ override ���ʿ䰡����(non-virtual)

	// �����Լ� : �Ļ�Ŭ������ override ���������� �ڽ��ǰ��� ������
	virtual void show() { cout << "shape show" << endl; }

	// ���� �����Լ� --> override ���ϸ� error
	virtual void draw() = 0;

	// ���� �����Լ��� �ʼ� �����Ǹ� �䱸�� �����ְ�
	// -1��.. defalut �������� ǥ���Ҽ�����
	virtual int get_area() { return -1; }
};

class Triangle:public shape
{
public:
	virtual void draw() { cout << "draw triangle" << endl; }
	virtual int get_area() { return 100; }
};

class Rect : public shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) :x(x), y(y), width(w), height(h)
	{

	}
	void draw() override { cout << "draw rect" << endl; }
	int get_area() override { return width * height; }
};

class Circle : public shape
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) :x(x), y(y), radius(r)
	{

	}
	void draw() override { cout << "draw circle" << endl; }
	int get_area() override { return radius * radius * PI; }
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
		else if (cmd == 3)
		{
			v.push_back(new Triangle);
		}
		else if (cmd == 9)
		{
			for (auto p : v) {
				p->draw(); // ���� p��Ÿ���� shaep �̱⶧���� 
			}
		}
	}

}