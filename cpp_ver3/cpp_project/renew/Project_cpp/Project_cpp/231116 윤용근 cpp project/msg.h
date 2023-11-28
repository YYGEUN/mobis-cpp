#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

// �޽��� Ŭ����
class SMSManager
{
	//������ �ߺ� �˻� dictionary
	std::map<std::string, int> userm;
	//���°��� key������ ������ ���Ϳ� ����� �������� value�� ���� dictionary --> key��ȣ�� ��ϵ� �����鿡�� �޼��������� ���
	std::map<std::string, std::vector<std::string>> m;
public:
	// �������
	void Add_User();
	// ��������
	void Delete_User();
	// ��ϵ� �������� �޼��� ����
	void Send_msg(const std::string& machine, const std::string& name, const std::string& state);
	// HomeAutomaiton ���� Ȥ�� �Ͻ����� �� usr.txt�� ��������
	void save_user(std::ofstream* ou);
	// HomeAutomaiton ����� user.txt ���� ��ϵ� ������ �ҷ��� --> �ҷ����� ������ ����
	void Road();
};