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

		cout << "================ 메인메뉴 ====================" << endl;
		cout << "1. 입력        2. 출력          3. 종료 " << endl;
		cout << "=============================================" << endl;
		cout << "번호를 입력하세요 : " ;
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
		cout << "몇개의 데이터를 입력하시겠습니까?" << endl;
		cin >> _memberNum;
		_list = new struct personInfo[_memberNum];

		_cnt = 0;
		while (_memberNum > _cnt)
		{
			cout << "<<" << _cnt + 1 << "번째 데이터 입력>>" << endl;
			cout << "이름: ";
			cin >> _name;
			cout << "나이: ";
			cin >> _age;
			cout << "주소: ";
			cin >> _address;

			_list[_cnt].name = _name;
			_list[_cnt].age = _age;
			_list[_cnt].address = _address;

			_cnt++; // 반복문 카운터를 증가시켜 무한 루프를 방지합니다.
		}
		
		system("cls");
		setMainPage();
	}


	void itemOutput()
	{
		int cnt = 0;
		if (_list == nullptr)
		{
			cout << "데이터가 없습니다." << endl;
			return;
		}
		while (_memberNum > cnt) {
			cout << "<<" <<cnt+1 <<">>" <<endl;
			cout << "이름:" << _list[cnt].name<<endl;
			cout << "나이:" << _list[cnt].age <<endl;
			cout << "주소:" << _list[cnt].address<< endl<<endl;
			cnt++;
		}
		cout << "임의숫자를 입력하면 메인페이지로 넘어갑니다" << endl;
		cin >> _cnt;
		
		system("cls");
		setMainPage();
	}


};

void main() {

	mainClass mc;



}

