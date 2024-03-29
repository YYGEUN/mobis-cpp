#include <iostream>
#include "menu.h"

// 아래 코드를 추가해 보세요

class Shape {}; // 여러분이 만드는 제품으로 변경하세요

class HomeAutomationSystem
{
	
	std::vector<Shape*> v; // 제품을 보관할 vector
public:
	HomeAutomationSystem() { init_menu(); }

	void init_menu() // init_menu(HomeAutomationSystem* this)
	{
		PopupMenu* root = new PopupMenu("ROOT");
		root->add( new MenuItem("제품등록", 11, foo) std::bind(&HomeAutomationSystem::add_product, this)));
									// => this->add_product()

		root->add( new MenuItem("제품삭제", 12, std::bind(&HomeAutomationSystem::remove_product, this)));

		root->command();
	}
	void add_product()
	{
		std::cout << "제품 등록 코드를 여기서 추가." << std::endl;
	}
	void remove_product()
	{
		std::cout << "제품 제거 코드을 여기서 추가" << std::endl;
	}
};
int main()
{
	HomeAutomationSystem has;

	add_product(); // error
	has.add_product(); // 
	function f = bind(&HomeAutomationSystem::add_product, &has);
}

