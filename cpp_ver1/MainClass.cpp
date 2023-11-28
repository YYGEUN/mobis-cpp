#include "MainClass.h"
#include <iostream>

MainClass::MainClass()
	:_guage(0),
	_PLevel(0)
{
	cout << "NEW ID" << endl;
}

MainClass::~MainClass()
{
	cout << "END" << endl;
}

MainClass::MainClass(int n, float guage)
	:_guage(guage),
	_PLevel(n)
{
	std::cout << _PLevel << std::endl;
	std::cout << _guage << std::endl;
}

MainClass::MainClass(int n) 
	:_guage(0),
	_PLevel(n)
{
	std::cout << _PLevel << std::endl;
	std::cout << _guage << std::endl;
}