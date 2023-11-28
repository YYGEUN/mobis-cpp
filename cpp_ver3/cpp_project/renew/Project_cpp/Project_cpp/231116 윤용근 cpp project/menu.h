#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>

//메뉴들 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}

	std::string get_title() { return title; }

	virtual ~BaseMenu() {}
	virtual void command() = 0;
};

// 반복문 팝업 메뉴
class PopupMenu : public BaseMenu
{
	std::vector<std::shared_ptr<BaseMenu>> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}
	int get_vsize() { return v.size(); }
	void add(std::shared_ptr <BaseMenu> p) { v.push_back(p); }
	void pop(int idx) { v.erase(v.begin() + idx); }

	void command();
};

// 일회성 팝업 메뉴
class TempMenu : public BaseMenu
{

	std::vector<std::shared_ptr<BaseMenu>> v;
public:
	TempMenu(const std::string& s) : BaseMenu(s) {}
	int get_vsize() { return v.size(); }
	void add(std::shared_ptr<BaseMenu> p) { v.push_back(p); }
	void pop(int idx) { v.erase(v.begin() + idx); }

	void command();
};

// 메뉴아이템 -> 함수 바인딩
class MenuItem : public BaseMenu
{
	using HANDLER = std::function<void()>;

	HANDLER handler;
public:
	MenuItem(const std::string& s, HANDLER h = nullptr)
		: BaseMenu(s), handler(h) {}

	void command();
};
