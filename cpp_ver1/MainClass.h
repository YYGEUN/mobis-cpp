#pragma once
#include <iostream>

using namespace std;
//.h ���
//.cpp ����� ����

class MainClass
{
	//private - ��ü�ڽŸ� ���ٰ��� (defalut ��) ** ����ü�� defalut�� public
	//protected - ��Ӱ��踸 ���ٰ���
	//public - �ܺ����� ����
	//�������� �����ڴ� ������ ����Ҽ��ִ�.

private:
	float _guage; /// private �Լ��̹Ƿ� ���� Ŭ���� �������� ��밡��
	int _PLevel;

public:
	//float _guage; /// ���� ������� main.cpp���� ����üó�� ���ٰ����ϴ�
	//int _num;
	//defalut ������ ������ �Ҹ��ڸ� ���������ʾƵ� ���� (�߰��� �����ؼ� ����Ҽ����ִ�)

	MainClass(); // ������ - ��ü�� �����Ǹ� �ڵ�ȣ�� -- �ߺ���������
	MainClass(int n);
	MainClass(int n,float guage);

	void Init(); // main_init ó�� ������ cpp ���Ͽ� �����Ͽ� ���ǰ��� --> ���ü�Ȯ��(���� ���⵵ ����)
	void Release();
	void Update();

	//echo(int);
	~MainClass(); // �Ҹ��� - ��ü �Ҹ�� �ڵ�ȣ�� -- �ߺ����� �Ұ� ����!
};
