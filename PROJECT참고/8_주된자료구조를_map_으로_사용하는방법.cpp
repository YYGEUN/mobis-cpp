#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "menu.h"

class Appliance {}; // 여러분이 만드는 제품으로 변경하세요

class HomeAutomationSystem
{
	
// 	std::vector<Appliance*> v; // 이 구조를
	std::map<std::string, std::vector<Appliance*>> m; // 이렇게 하는 것도
														// 나쁘지 않습니다.
public:
	void add_product()
	{

		m["aircon"].push_back( new aircon("이름1"));
		m["aircon"].push_back( new aircon("이름2"));

		m["light"].push_back( new aircon("light1"));
		m["light"].push_back( new aircon("light2"));
	}

};
int main()
{
	HomeAutomationSystem has;
}

