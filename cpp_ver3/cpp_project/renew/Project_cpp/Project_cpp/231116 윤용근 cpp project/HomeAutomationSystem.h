#pragma once
#include "menu.h"
#include "appliance.h"

// Ȩ������̼� Ŭ����
class HomeAutomationSystem
{
	std::vector<BaseInfo*> v; // ��ǰ�� ������ vector
	std::map<std::string, std::vector<std::shared_ptr <BaseInfo>>> vm; //key���� ��ǰ ���� value�� Baseinfo�� ������ ������
	std::map<std::string, int> namem; //�ߺ��̸� ó��
	std::map<std::string, int> costm; //������ ������ǰ�� ������� --> ��ǰŸ�Կ� ���ؼ� �з��ϰ� ������
	std::vector<std::string> typev = { "��Ź��","������","����","����" }; // ��ǰ Ÿ�� ����
public:
	HomeAutomationSystem() { init_menu(); }
	// Ȩ������̼� ����� �ʱ� ������ 
	void init_menu();
	// Ȩ������̼� ����� ����� �ڷᰡ ������ �ҷ����� --> �ҷ����� ������ ����
	void Road();
	// �Ͻ� ���� --> ��ǰ���� �����Ű���ʰ� ���� ���� �״�� ����, (Ȩ������̼� ���۽� �������¿� �̾ ���۵�)
	void Go_OUT() ;
	// ���� --> ��ǰ���� �����Ű�� ����, (Ȩ������̼� ���۽� OFF �Ȼ��·� �ʱ�ȭ)
	void Shut_Down();
	// ���� ��ϵ� ��ǰ���� �˾� ��Ű�� ������ �޴����ÿ� ���� ó���Լ��� ������
	void Create_List(int casenum);
	// ���� ����
	void All_PowerOFF();
	// ���� �ѱ�
	void All_PowerON();
	// ��ǰ �߰� --> �ʱ⼳���� ��ǰ��ϵ��� �߰� ���ý� �ش��ϴ� ��ǰ�� �ʼ������� �Է¹޾Ƽ� ����
	void add_product(int n);
	// ��ǰ ���� --> use_h ���� , costm ���� �� ����
	void delete_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);
	// ��ǰ ���� ��� --> �� ������ show�Լ��� ����
	void show_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);
	// ��ǰ ���� --> �� ������ control�Լ��� ����
	void control_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);

	// ���� ���ý� ������ �����Ű�� ��� ��� ���
	void show_rate();
	// ���� �ð��� �������� ��� ��� ��� -- ���ű��
	void calculate_rate();
	// ���� ���� �޴� --> ���� �� ����
	void Create_User_Menu();
};