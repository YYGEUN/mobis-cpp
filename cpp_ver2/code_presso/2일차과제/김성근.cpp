#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

enum LOCATION
{
	Input = 1,
	Output,
	Terminate
};

struct personInfo
{
	string name;			
	int age;					
	string address;				
};



class  mainClass {

private:
	int  _selectNum;
	int  _cnt;
	int _memberNum;
	struct personInfo* _list;

	string _name;
	int _age;
	string _address;



public:
	mainClass()
	{
		setMainPage();
	}
	~mainClass()
	{

	}

	void setMainPage()
	{

		cout << "================ ���θ޴� ====================" << endl;
		cout << "1. �Է�        2. ���          3. ���� " << endl;
		cout << "=============================================" << endl;
		cout << "��ȣ�� �Է��ϼ��� : " ;
		cin >> _selectNum;
		//system("cls");
		
		setLocation(_selectNum);
		

	}



	void setLocation(int number)
	{
		switch (number)
		{
		case Input:
			createMember();
			break;
		case Output:
			itemOutput();
			break;
		case Terminate:
			return;
			break;

		default:
			//setMainPage();
			break;
		}

	}


	void createMember()
	{
		cout << "��� �����͸� �Է��Ͻðڽ��ϱ�?" << endl;
		cin >> _memberNum;
		_list = new struct personInfo[_memberNum];

		_cnt = 0;
		while (_memberNum > _cnt)
		{
			cout << "<<" << _cnt + 1 << "��° ������ �Է�>>" << endl;
			cout << "�̸�: ";
			cin >> _name;
			cout << "����: ";
			cin >> _age;
			cout << "�ּ�: ";
			cin >> _address;

			_list[_cnt].name = _name;
			_list[_cnt].age = _age;
			_list[_cnt].address = _address;

			_cnt++; // �ݺ��� ī���͸� �������� ���� ������ �����մϴ�.
		}
		
		system("cls");
		setMainPage();
	}


	void itemOutput()
	{
		int cnt = 0;
		if (_list == nullptr)
		{
			cout << "�����Ͱ� �����ϴ�." << endl;
			return;
		}
		while (_memberNum > cnt) {
			cout << "<<" <<cnt+1 <<">>" <<endl;
			cout << "�̸�:" << _list[cnt].name<<endl;
			cout << "����:" << _list[cnt].age <<endl;
			cout << "�ּ�:" << _list[cnt].address<< endl<<endl;
			cnt++;
		}
		cout << "���Ǽ��ڸ� �Է��ϸ� ������������ �Ѿ�ϴ�" << endl;
		cin >> _cnt;
		
		system("cls");
		setMainPage();
	}


};

void main() {

	mainClass mc;



}

