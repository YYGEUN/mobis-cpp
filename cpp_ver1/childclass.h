#pragma once
#include "motherclass.h"

class childclass : public motherclass
{
public:
	childclass() {
		cout << "자식 클래스 생성" << endl;
		_livingMoney = 7000; // protected 까지 접근 가능
		//_Megg = 1000; // private 접근 불가
	}

	~childclass() {
		cout << "자식 클래스 소멸" << endl;
	}
};

class lastclass : public childclass
{
public:
	lastclass() {
		cout << "라스트 클래스 생성" << endl;
		_livingMoney = 9000; // protected 까지 접근 가능
		//_Megg = 1000; // private 접근 불가
	}

	~lastclass() {
		cout << "라스트 클래스 소멸" << endl;
	}
};