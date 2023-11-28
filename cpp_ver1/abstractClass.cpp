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
	cout << "이름 : " << _name << endl;
	cout << "현재 : " << _current << "(최대치 : " << _max << ")" << endl;
}