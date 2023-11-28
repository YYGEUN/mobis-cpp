#include "functions.h"
#include <Windows.h>
#include <ctime>

int checkintonly(int* cmd, std::string s) {
	while (1) {
		std::cin >> *cmd;
		if (std::cin.fail()) {
			std::cin.clear();  // 에러 상태 초기화
			std::cin.ignore(256, '\n');  // 입력 버퍼 비우기
			std::cout << "잘못된 입력입니다. 다시 정수를 입력하세요. ";
			std::cout << "나가기 (YES : 0)\n";
			std::cout << "\n▶ " << s << " 입력 : ";
			return -1;
		}
		else if (std::cin.get() != '\n') {
			std::cout << "잘못된 입력입니다. 다시 정수를 입력하세요. ";
			std::cout << "나가기 (YES : 0)\n";
			std::cin.clear();  // 에러 상태 초기화
			std::cin.ignore(256, '\n');  // 입력 버퍼 비우기
			std::cout << "\n▶ " << s << " 입력 : ";
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
			std::cin.clear();  // 에러 상태 초기화
			std::cin.ignore(256, '\n');  // 입력 버퍼 비우기
			std::cout << "잘못된 입력입니다. 다시 정수를 입력하세요. ";
			std::cout << "나가기 (YES : 0)\n";
			std::cout << "\n▶ " << s << " 입력 : ";
			return -1;
		}
		else if (std::cin.get() != '\n') {
			std::cout << "잘못된 입력입니다. 다시 정수를 입력하세요. ";
			std::cout << "나가기 (YES : 0)\n";
			std::cout << "\n▶ " << s << " 입력 : ";
			std::cin.clear();
			std::cin.ignore(256, '\n');  // 입력 버퍼 비우기
			return -1;
		}
		else if (*cmd < 0 || *cmd > size) {
			std::cout << "잘못된 입력입니다. 범위내에서 입력하세요. ";
			std::cout << "나가기 (YES : 0)\n";
			std::cout << "\n▶ " << s << " 입력 : ";
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
	std::cout << "나가기 (Press 0)\n";
	std::cout << "\n▶ " << s << " 입력 : ";
	return;
}