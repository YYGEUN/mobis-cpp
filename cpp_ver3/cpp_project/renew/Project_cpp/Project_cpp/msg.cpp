#include "msg.h"
#include <Windows.h>
#include <fstream>
#include "functions.h"

void SMSManager::Add_User()
{
	std::string name;
	std::cout << "▶ 이름 입력 : ";
	std::cin >> name;
	if (userm[name] == 1) {
		std::cout << "중복된 이름 입니다. 다시입력하세요\n";
		std::cin.clear();
		Add_User();
		return;
	}
	m["ON"].push_back(name);
	m["OFF"].push_back(name);
	userm[name] = 1;
	std::cout << name << " 등록됨" << std::endl;
	Sleep(1000);
}

void SMSManager::Delete_User()
{
	if (m["ON"].size() == 0) {
		std::cout << "등록된 유저가없습니다\n" << std::endl;
		Sleep(1000);
		return;
	}

	for (int i = 0; i < m["ON"].size(); i++) {
		std::cout << i + 1 << ". " << m["ON"][i] << std::endl;
	}

	std::cout << "\n▶ 번호 입력 : ";
	int cmd;
	while (checkint(&cmd, m["ON"].size(), "번호") == -1) {}

	if (cmd == 0) { return; }

	for (auto n : m) {
		std::cout << n.first << " Event : " << m[n.first][cmd - 1] << " 삭제됨" << std::endl;
		m[n.first].erase(m[n.first].begin() + cmd - 1);
	}
	Sleep(1000);
}

void SMSManager::Send_msg(const std::string& machine, const std::string& name, const std::string& state)
{
	for (int i = 0; i < m[state].size(); i++) {
		printf("%s : %s(%s) %s\n", m[state][i].c_str(), name.c_str(), machine.c_str(), state.c_str());
	}
}

void SMSManager::save_user(std::ofstream* ou)
{
	for (int i = 0; i < m["ON"].size(); i++) {
		if (ou->is_open()) {
			*ou << m["ON"][i] << std::endl;
		}
	}
}

void SMSManager::Road()
{
	std::ifstream iu("user.txt");
	std::string name;
	while (std::getline(iu, name)) {
		m["ON"].push_back(name);
		m["OFF"].push_back(name);
	}
	iu.close();

	if (std::remove("user.txt") != 0) {
		perror("Error deleting the file");
	}
}
