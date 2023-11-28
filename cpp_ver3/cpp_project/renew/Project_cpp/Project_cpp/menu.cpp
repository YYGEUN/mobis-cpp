#include "menu.h"
#include "functions.h"

void PopupMenu::command()
{
	while (1)
	{
		system("cls");

		int sz = v.size();
		std::cout << "==========================================\n";
		for (int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
		};
		std::cout << "==========================================\n";

		int cmd = 0;
		std::cout << "\n�� ��ȣ �Է� : ";

		while (checkint(&cmd, v.size(), "��ȣ") == -1) {}

		if (cmd == 0) {
			//std::cout << "�߸��� �Է��Դϴ�. ���������� �Է��ϼ���. ";
			continue;
		}

		if (cmd == v.size() || cmd == v.size() - 1) {
			v[cmd - 1]->command();
			break;
		}

		v[cmd - 1]->command();
	}
}
void TempMenu::command()
{
	system("cls");

	int sz = v.size();
	std::cout << "==========================================\n";
	for (int i = 0; i < sz; i++)
	{
		std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
	};
	std::cout << "==========================================\n";
	std::cout << "������ (Press 0)\n";

	int cmd;
	std::cout << "\n�� ��ȣ �Է� : ";
	while (checkint(&cmd, v.size(), "��ȣ") == -1) {}

	if (cmd == 0) return;

	v[cmd - 1]->command();
}
void MenuItem::command()
{
	if (handler != nullptr)
		handler();
}