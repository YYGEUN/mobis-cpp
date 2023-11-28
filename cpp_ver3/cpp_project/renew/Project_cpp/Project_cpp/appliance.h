#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <fstream>
#include <vector>

//������ �⺻ �������� ��� ��� Ŭ����
class BaseInfo
{
private:
	std::string name; // ���� �̸�
	std::string type; // ���� Ÿ��
	std::string state1; // ���� ���� ex) ����, �ù� ��...
	int Power; // ���� ���� 0-->OFF 1-->ON
	int powerconsumtion; // ���¼Һ�
	time_t Use_H; // ���ð�
	time_t Start_H; // ��� ���۽ð�
public:
	// �⺻ ������
	BaseInfo(const std::string s, int cmd, const std::string& type)
		:Power(0), state1("�����"), Use_H(0), Start_H(0), name(s), type(type), powerconsumtion(cmd) {}

	// �ε�� ���Ǵ� ������
	BaseInfo(const std::string s, int cmd, const std::string& type, int power, int use_h)
		:Power(power), state1("�����"), Use_H(use_h), Start_H(0), name(s), type(type), powerconsumtion(cmd) {}

	std::string get_type();
	std::string get_name();
	std::string get_state1();
	int get_powerconsumtion();
	int get_Use_H();
	int get_Start_H();
	int get_Power();
	
	// �����Ѱ� Start_H ����
	void turn_on();
	// �������� Use_H ����
	void turn_off();

	void set_state1(std::string& s);
	void set_Use_H(time_t t);
	void set_Strat_H(time_t t);
	void set_PowerON();
	void set_PowerOFF();

	void save(std::ofstream* f);

	// �� ������ ��Ʈ�� �Լ��� �������̵� (�����Լ�)
	virtual void Control() = 0;

	// �� ������ ��������(SHOW) �Լ��� �������̵� (�����Լ�)
	virtual void Show() = 0;

	// �� ������ ����(SAVE) �Լ��� �������̵� (�����Լ�)
	virtual void save_state(std::ofstream* f);

	virtual ~BaseInfo() {}
};

// ���� ������ Ŭ����
class Aircon : public BaseInfo
{
	// ������ ���� ���� ���� 
	std::vector<std::string> v = { "����","�ù�","����" };
	// ������ �޴� ���� ����
	std::vector<std::string> menuv = { "���� ON","���� OFF","������ ���","�µ� ����" };
	int temperature;
public:
	//������ �⺻������
	Aircon(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type), temperature(25) {}
	//�ε�� ������ ������
	Aircon(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h), temperature(25) {}
	
	void set_temperature(int t);
	
	// ������ ���� ���
	void Show() override;
	// �޴����� ���͸� �ҷ����� ���ÿ� ���� ���� ���� �Լ�
	void Control() override;
	// �������� �߰� ���� ���̺�
	void save_state(std::ofstream* f) override;
};
// ���� ��Ź�� Ŭ����
class Washer : public BaseInfo
{
	std::vector<std::string> v = { "����","�Ϲݼ�Ź","������Ź" };
	std::vector<std::string> menuv = { "���� ON","���� OFF","��Ź�� ���" };
public:
	//��Ź�� �⺻������
	Washer(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//�ε�� ��Ź�� ������
	Washer(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// ��Ź�� ���� ���
	void Control() override;
	// �޴����� ���͸� �ҷ����� ���ÿ� ���� ���� ���� �Լ�
	void Show() override;
	// ��Ź�� �߰� ���� ���̺�
	void save_state(std::ofstream* f) override;
};
// ���� ���� Ŭ����
class Light : public BaseInfo
{
	std::vector<std::string> menuv = { "���� ON","���� OFF" };
public:
	//���� �⺻������
	Light(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//�ε�� ���� ������
	Light(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// ���� ���� ���
	void Control() override;
	// �޴����� ���͸� �ҷ����� ���ÿ� ���� ���� ���� �Լ�
	void Show() override;
	// ���� �߰� ���� ���̺�
	void save_state(std::ofstream* f) override;
};
// ���� ���� Ŭ����
class CooCoo : public BaseInfo
{
	std::vector<std::string> v = { "����","���","������" };
	std::vector<std::string> menuv = { "���� ON","���� OFF","���� ���"};
public:
	//���� �⺻������
	CooCoo(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//�ε�� ���� ������
	CooCoo(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// ���� ���� ���
	void Control() override;
	// �޴����� ���͸� �ҷ����� ���ÿ� ���� ���� ���� �Լ�
	void Show() override;
	// ���� �߰� ���� ���̺�
	void save_state(std::ofstream* f) override;
};
