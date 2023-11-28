#pragma once
#include <iostream>

using namespace std;

class Sweet {
private:
protected:
	string _name;
	int _current;
	int _max;
public:
	Sweet();
	virtual ~Sweet();
	// 클래스 내부에 가상함수가 있으면 virtual 소멸자를 설정해야함
	// 가상 소멸자가없다면 base로 사용되는 클래스는 아닐것
	// 반면 상속을 하지않을 클래스에 가상소멸자를 두면 vptr 함수를 잡으므로 객체의 크기가 커질수있는 단점이있음

	virtual void set(string name, int cur, int max);
	void output();

	virtual void func() abstract; // virtual void func() = 0; 같은의미

};


class Candy
	:public Sweet
{
public:
	// 부모의 추상클래스를 반드시 오버라이드 해줘야 사용가능함
	virtual void func() override
	{
		cout << "사탕!" << endl;
	}
};

class Gacha
	:public Sweet
{
public:
	// 부모의 추상클래스를 반드시 오버라이드 해줘야 사용가능함
	virtual void func() override
	{
		cout << "뽑기!" << endl;
	}
};