#pragma once
#include <iostream>
#include <string>
#include <vector>

//���͸� �ް� ���� ��� �ϴ� �Լ�
template<typename T>
void printv(std::vector<T> v, const std::string s);

// �������� �Ǻ��ϴ� �Լ� 1
int checkintonly(int* cmd, std::string s);

// ���� �ð������� �Լ�
int Get_time();

// �������� �Ǻ��ϴ� �Լ� 2 (1�� ��ɿ� �޴� �������� �����ؾ� �ϴ±�� �߰�)
int checkint(int* cmd, int size, const std::string s);
