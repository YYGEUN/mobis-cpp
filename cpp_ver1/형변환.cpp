#include <iostream>

using namespace std;

void main() {
	//static_cast----------------------------------------------------------------------------------
	//���� ĳ���� 
	//�����Ͻ� ����ȯ�� �������� �˻��� ��ȯ�� ���� --> �Ұ��ɽ� �����Ͽ���

	float speed = 123.123f;
	int av = 312;
	int* a = &av;
	cout << static_cast<int>(speed) << endl;

	speed = (int)speed;

	int* speedmeter = (int*)&speed; // ��������ȯ�̹Ƿ� �ٲٰ� ������ ��Ŵ
	//int* speedmeter = static_cast<int*>(&(speed)); //--> ����ȯ ���ɼ���(���輺) ���� �����ϹǷ� �Ұ����ϸ� ������ �Ұ�

	// ��Ӱ��迡�� �����ͳ��� ĳ������ ���

	cout << a << "     " << av << endl;
	cout << speedmeter << endl;

	//reinterpret_cast----------------------------------------------------------------------------------
	//c ĳ���� ��İ� ���(��������ȯ)
	//������ Ÿ���� �Ϲ� ����Ÿ�����ε� ĳ������ ����   ������ <---> �Ϲݺ��� ��� ����

	int* speedmeter2 = reinterpret_cast<int*>(&(speed));

	cout << speedmeter2 << endl;

	int number = 65;
	char* cptr = reinterpret_cast<char*>(&number);

	cout << cptr << endl;

	//const_cast----------------------------------------------------------------------------------
	//����� ��ȿȭ ���ִ±��
	
	const char* str = "�Ѽ��̹ٺ�";

	cout << str << endl;

	char* str2 = const_cast<char*>(str);

	cout << str2 << endl; 

	return;
}