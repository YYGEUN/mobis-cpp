#include "msg.h"
#include <Windows.h>
#include <fstream>
#include "functions.h"

void SMSManager::Add_User()
{
	std::string name;
	std::cout << "�� �̸� �Է� : ";
	std::cin >> name;
	if (userm[name] == 1) {
		std::cout << "�ߺ��� �̸� �Դϴ�. �ٽ��Է��ϼ���\n";
		std::cin.clear();
		Add_User();
		return;
	}
	m["ON"].push_back(name);
	m["OFF"].push_back(name);
	userm[name] = 1;
	std::cout << name << " ��ϵ�" << std::endl;
	Sleep(1000);
}

void SMSManager::Delete_User()
{
	if (m["ON"].size() == 0) {
		std::cout << "��ϵ� �����������ϴ�\n" << std::endl;
		Sleep(1000);
		return;
	}

	for (int i = 0; i < m["ON"].size(); i++) {
		std::cout << i + 1 << ". " << m["ON"][i] << std::endl;
	}

	std::cout << "\n�� ��ȣ �Է� : ";
	int cmd;
	while (checkint(&cmd, m["ON"].size(), "��ȣ") == -1) {}

	if (cmd == 0) { return; }

	for (auto n : m) {
		std::cout << n.first << " Event : " << m[n.first][cmd - 1] << " ������" << std::endl;
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
