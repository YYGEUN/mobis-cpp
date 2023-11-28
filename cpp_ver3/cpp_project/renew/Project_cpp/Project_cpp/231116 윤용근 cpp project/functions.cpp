#include "functions.h"
#include <Windows.h>
#include <ctime>

int checkintonly(int* cmd, std::string s) {
	while (1) {
		std::cin >> *cmd;
		if (std::cin.fail()) {
			std::cin.clear();  // ���� ���� �ʱ�ȭ
			std::cin.ignore(256, '\n');  // �Է� ���� ����
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �Է��ϼ���. ";
			std::cout << "������ (YES : 0)\n";
			std::cout << "\n�� " << s << " �Է� : ";
			return -1;
		}
		else if (std::cin.get() != '\n') {
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �Է��ϼ���. ";
			std::cout << "������ (YES : 0)\n";
			std::cin.clear();  // ���� ���� �ʱ�ȭ
			std::cin.ignore(256, '\n');  // �Է� ���� ����
			std::cout << "\n�� " << s << " �Է� : ";
			return -1;
		}
		else {
			return *cmd;
		}
	}
}

int Get_time() {
	time_t timer;
	timer = time(NULL);
	return timer;
};

int checkint(int* cmd, int size, const std::string s) {
	while (1) {
		std::cin >> *cmd;
		if (std::cin.fail()) {
			std::cin.clear();  // ���� ���� �ʱ�ȭ
			std::cin.ignore(256, '\n');  // �Է� ���� ����
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �Է��ϼ���. ";
			std::cout << "������ (YES : 0)\n";
			std::cout << "\n�� " << s << " �Է� : ";
			return -1;
		}
		else if (std::cin.get() != '\n') {
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �Է��ϼ���. ";
			std::cout << "������ (YES : 0)\n";
			std::cout << "\n�� " << s << " �Է� : ";
			std::cin.clear();
			std::cin.ignore(256, '\n');  // �Է� ���� ����
			return -1;
		}
		else if (*cmd < 0 || *cmd > size) {
			std::cout << "�߸��� �Է��Դϴ�. ���������� �Է��ϼ���. ";
			std::cout << "������ (YES : 0)\n";
			std::cout << "\n�� " << s << " �Է� : ";
			std::cin.clear();
			return -1;
		}
		else {
			return *cmd;
		}
	}
}

template<typename T>
void printv(std::vector<T> v, const std::string s) {
	std::cout << "==========================================\n";
	for (int i = 0; i < v.size(); i++) {
		std::cout << i + 1 << ". " << v[i] << std::endl;
	}
	std::cout << "==========================================\n";
	std::cout << "������ (Press 0)\n";
	std::cout << "\n�� " << s << " �Է� : ";
	return;
}