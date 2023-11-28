#include "HomeAutomationSystem.h"
#include "msg.h"
#include "functions.h"

extern SMSManager sms;

void HomeAutomationSystem::init_menu()
{
	Road();
	sms.Road();
	std::shared_ptr <PopupMenu> root = std::make_shared<PopupMenu>("Root");
	std::shared_ptr <TempMenu> pm1 = std::make_shared<TempMenu>("��ǰ���");
	root->add(pm1);

	for (int i = 0; i < typev.size(); i++)
	{
		pm1->add(std::make_shared<MenuItem>(typev[i], std::bind(&HomeAutomationSystem::add_product, this, i + 1)));
	}
	root->add(std::make_shared<MenuItem>("��ǰ����", std::bind(&HomeAutomationSystem::Create_List, this, 1)));
	root->add(std::make_shared<MenuItem>("��ǰ����", std::bind(&HomeAutomationSystem::Create_List, this, 2)));
	root->add(std::make_shared<MenuItem>("��ǰ����", std::bind(&HomeAutomationSystem::Create_List, this, 3)));
	root->add(std::make_shared<MenuItem>("��������", std::bind(&HomeAutomationSystem::Create_User_Menu, this)));
	root->add(std::make_shared<MenuItem>("�����ȸ", std::bind(&HomeAutomationSystem::calculate_rate, this)));
	root->add(std::make_shared<MenuItem>("������", std::bind(&HomeAutomationSystem::Go_OUT, this)));
	root->add(std::make_shared<MenuItem>("���� (��ü���� OFF)", std::bind(&HomeAutomationSystem::Shut_Down, this)));

	root->command();
}

void HomeAutomationSystem::Road()
{
	for (int i = 0; i < typev.size(); i++) {
		std::ifstream f(typev[i] + ".txt");
		std::string type;
		std::string name;
		std::string state1;
		std::string power_string;
		std::string powerconsumtion_string;
		std::string use_h_string;
		while (std::getline(f, type)) {
			std::getline(f, name);
			std::getline(f, state1);
			std::getline(f, power_string);
			std::getline(f, powerconsumtion_string);
			std::getline(f, use_h_string);
			if (type == "������") {
				vm[type].push_back(std::make_shared<Aircon>(name, std::stoi(powerconsumtion_string), type, std::stoi(power_string), std::stoi(use_h_string)));
			}
			else if (type == "��Ź��") {
				vm[type].push_back(std::make_shared<Washer>(name, std::stoi(powerconsumtion_string), type, std::stoi(power_string), std::stoi(use_h_string)));
			}
			else if (type == "����") {
				vm[type].push_back(std::make_shared<CooCoo>(name, std::stoi(powerconsumtion_string), type, std::stoi(power_string), std::stoi(use_h_string)));
			}
			else if (type == "����") {
				vm[type].push_back(std::make_shared<Light>(name, std::stoi(powerconsumtion_string), type, std::stoi(power_string), std::stoi(use_h_string)));
			}
		}
		f.close();
		std::string imsi = typev[i] + ".txt";
		if (std::remove(imsi.c_str()) != 0) {
			perror("Error deleting the file");
		}
	}
}

void HomeAutomationSystem::Go_OUT()
{
	std::cout << "������" << std::endl;

	for (auto& n : vm) {
		int money = 0;
		for (int i = 0; i < vm[n.first].size(); i++) {
			if (vm[n.first][i]->get_Power() != 0) {
				money += (Get_time() - vm[n.first][i]->get_Start_H()) * vm[n.first][i]->get_powerconsumtion();
				vm[n.first][i]->set_Use_H(Get_time() - vm[n.first][i]->get_Start_H());
				vm[n.first][i]->set_Strat_H(0);
			}

			std::ofstream f(n.first + ".txt", std::ios::app);
			vm[n.first][i]->save(&f);
		}
		costm[n.first] += money;
	}

	std::ofstream ou("user.txt", std::ios::app);
	sms.save_user(&ou);
}

void HomeAutomationSystem::Shut_Down()
{
	std::cout << "�ý��� ����" << std::endl;

	for (auto& n : vm) {
		int money = 0;
		for (int i = 0; i < vm[n.first].size(); i++) {
			if (vm[n.first][i]->get_Power() != 0) {
				vm[n.first][i]->turn_off();
				money += vm[n.first][i]->get_Use_H() * vm[n.first][i]->get_powerconsumtion();
			}

			std::ofstream f(n.first + ".txt", std::ios::app);
			vm[n.first][i]->save(&f);
		}
		costm[n.first] += money;
	}
	std::ofstream ou("user.txt", std::ios::app);
	sms.save_user(&ou);
	show_rate();
}

void HomeAutomationSystem::Create_List(int casenum)
{
	system("CLS");

	std::shared_ptr <TempMenu> root = std::make_shared<TempMenu>("nothing");
	if (casenum == 3) {
		root->add(std::make_shared<MenuItem>("���� �ѱ�", std::bind(&HomeAutomationSystem::All_PowerON, this)));
		root->add(std::make_shared<MenuItem>("���� ����", std::bind(&HomeAutomationSystem::All_PowerOFF, this)));
	}
	for (auto& n : vm) {
		std::shared_ptr <TempMenu> pm = std::make_shared<TempMenu>(n.first);
		if (vm[n.first].size() != 0) {
			root->add(pm);
		}
		switch (casenum)
		{
		case 1:
			for (int i = 0; i < vm[n.first].size(); i++) {
				pm->add(std::make_shared<MenuItem>(n.second[i]->get_name(),
					std::bind(&HomeAutomationSystem::delete_product, this, i, n.first, std::ref(pm))));
			}
			break;
		case 2:
			for (int i = 0; i < vm[n.first].size(); i++) {
				pm->add(std::make_shared<MenuItem>(n.second[i]->get_name(),
					std::bind(&HomeAutomationSystem::show_product, this, i, n.first, std::ref(pm))));
			}
			break;
		case 3:
			for (int i = 0; i < vm[n.first].size(); i++) {
				pm->add(std::make_shared<MenuItem>(n.second[i]->get_name(),
					std::bind(&HomeAutomationSystem::control_product, this, i, n.first, std::ref(pm))));
			}
			break;
		default:
			break;
		}
	}

	root->command();
}

void HomeAutomationSystem::All_PowerOFF()
{
	std::cout << "ALL Device POWER OFF\n" << std::endl;
	for (auto n : vm) {
		for (int i = 0; i < vm[n.first].size(); i++) {
			vm[n.first][i]->turn_off();
			sms.Send_msg(n.first, vm[n.first][i]->get_name(), "OFF");
		}
	}
	while (1) {
		int cmd;
		std::cout << "\n������ (Press 0), �߰����� (Press 1)\n";
		std::cout << "\n�� ��ȣ �Է� : ";
		while (checkint(&cmd, 2, "��ȣ") == -1) {}
		if (cmd == 0) break;
		if (cmd == 1) {
			Create_List(3);
			break;
		}
	}
}

void HomeAutomationSystem::All_PowerON()
{
	std::cout << "ALL Device POWER ON\n" << std::endl;
	for (auto n : vm) {
		for (int i = 0; i < vm[n.first].size(); i++) {
			vm[n.first][i]->turn_on();
			sms.Send_msg(n.first, vm[n.first][i]->get_name(), "ON");
		}
	}
	while (1) {
		int cmd;
		std::cout << "\n������ (Press 0), �߰����� (Press 1)\n";
		std::cout << "\n�� ��ȣ �Է� : ";
		while (checkint(&cmd, 2, "��ȣ") == -1) {}
		if (cmd == 0) break;
		if (cmd == 1) {
			Create_List(3);
			break;
		}
	}
}

void HomeAutomationSystem::add_product(int n)
{
	std::string name;
	std::cout << "�� �̸� �Է� : ";
	std::cin >> name;
	if (namem[name] == 1) {
		std::cout << "�ߺ��� �̸� �Դϴ�. �ٽ��Է��ϼ���\n";
		std::cin.clear();
		add_product(n);
		return;
	}

	int cmd;
	std::cout << "�� �Һ����� �Է� : ";
	while (checkintonly(&cmd,"�Һ�����") == -1) {}

	if (cmd == 0) { return; }

	if (n == 1) {
		vm[typev[n - 1]].push_back(std::make_shared<Washer>(name, cmd, typev[n - 1]));
	}
	else if (n == 2) {
		vm[typev[n - 1]].push_back(std::make_shared<Aircon>(name, cmd, typev[n - 1]));
	}
	else if (n == 3) {
		vm[typev[n - 1]].push_back(std::make_shared<CooCoo>(name, cmd, typev[n - 1]));
	}
	else if (n == 4) {
		vm[typev[n - 1]].push_back(std::make_shared<Light>(name, cmd, typev[n - 1]));
	}
	namem[name] = 1;
}

void HomeAutomationSystem::delete_product(int idx, const std::string s, std::shared_ptr<TempMenu> pm)
{
	vm[s][idx]->turn_off();
	costm[s] += vm[s][idx]->get_Use_H() * vm[s][idx]->get_powerconsumtion();
	namem[vm[s][idx]->get_name()] = 0;
	vm[s].erase(vm[s].begin() + (idx));
}

void HomeAutomationSystem::show_product(int idx, const std::string s, std::shared_ptr<TempMenu> pm)
{
	system("CLS");
	vm[s][idx]->Show();

	while (1) {
		int cmd;
		std::cout << "������ (Press 0), ������ (Press 1)\n";
		std::cout << "\n�� ��ȣ �Է� : ";
		while (checkint(&cmd, 2, "��ȣ") == -1) {}
		if (cmd == 0) break;
		if (cmd == 1) {
			Create_List(2);
			break;
		}
	}
}

void HomeAutomationSystem::control_product(int idx, const std::string s, std::shared_ptr<TempMenu> pm)
{
	system("CLS");
	vm[s][idx]->Control();
}

void HomeAutomationSystem::show_rate()
{
	system("CLS");
	int total = 0;
	std::cout << "==========================================\n";
	for (auto& n : typev) {
		printf("%s : %d��\n", n.c_str(), costm[n]);
		total += costm[n];
	}
	std::cout << "�ѿ�� : " << total << "��" << std::endl;
	std::cout << "==========================================\n";
}

void HomeAutomationSystem::calculate_rate()
{
	system("CLS");
	int total = 0;
	std::cout << "==========================================\n";
	for (auto& n : typev) {
		int money = 0;
		for (int i = 0; i < vm[n].size(); i++) {
			if (vm[n][i]->get_Power() != 0) {
				money += (Get_time() - vm[n][i]->get_Start_H()) * vm[n][i]->get_powerconsumtion();
			}
		}
		money += costm[n];
		printf("%s : %d��\n", n.c_str(), money);
		total += money;
	}
	std::cout << "�ѿ�� : " << total << "��" << std::endl;
	std::cout << "==========================================\n";

	while (1) {
		int cmd;
		std::cout << "������ (Press 0), ���� (Press 1)\n";
		std::cout << "\n�� ��ȣ �Է� : ";
		while (checkint(&cmd, 2, "��ȣ") == -1) {}
		if (cmd == 0) break;
		if (cmd == 1) {
			calculate_rate();
			break;
		}
		system("CLS");
	}
}

void HomeAutomationSystem::Create_User_Menu()
{
	system("CLS");
	std::shared_ptr <TempMenu> root = std::make_shared<TempMenu>("nothing");
	root->add(std::make_shared<MenuItem>("�������", std::bind(&SMSManager::Add_User, std::ref(sms))));
	root->add(std::make_shared<MenuItem>("��������", std::bind(&SMSManager::Delete_User, std::ref(sms))));
	root->command();
}
