#pragma once
#include <iostream>
#include <string>
#include <vector>

//벡터를 받고 내용 출력 하는 함수
template<typename T>
void printv(std::vector<T> v, const std::string s);

// 숫자인지 판별하는 함수 1
int checkintonly(int* cmd, std::string s);

// 현재 시간얻어오는 함수
int Get_time();

// 숫자인지 판별하는 함수 2 (1의 기능에 메뉴 갯수내로 지정해야 하는기능 추가)
int checkint(int* cmd, int size, const std::string s);
