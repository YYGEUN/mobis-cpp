#include "abstractClass.h"

Sweet::Sweet()
{
}

Sweet::~Sweet()
{
}

void Sweet::set(string name, int cur, int max)
{
	_name = name;
	_current = cur;
	_max = max;
}

void Sweet::output() {
	cout << "�̸� : " << _name << endl;
	cout << "���� : " << _current << "(�ִ�ġ : " << _max << ")" << endl;
}