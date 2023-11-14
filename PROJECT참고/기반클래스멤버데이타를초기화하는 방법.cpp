#include <string>

class Base
{
	// 1. name 이라는 멤버는 기반 클래스에 있습니다
	std::string name;
	std::string other_member;
public:
	// 2. Base 의 생성자에서 자신의 멤버를 초기화 합니다.
	Base(const std::string& name, const std::string& other_member)
		: name(name), other_member(other_member) {}
};

class Derived : public Base 
{
	int power;
public:
	// 3. 파생 클래스 생성자는 자신의 고유 멤버를 초기화 하기 위한 인자뿐 아니라
	//    기반 클래스에서 상속 받은 멤버를 초기화 하기 위한 값도 생성자로 받아야 합니다.
	Derived( const std::string& name, const std::string& other_member, int power)
		: Base(name, other_member), power(power) {}

	// 핵심 : 자신의 멤버 데이타는 자신이 직접 초기화 하지만
	//       기반 클래스의 멤버는 기반 클래스의 생성자로 보내서 초기화 되게 합니다.
};

int main()
{
	Derived* p = new Derived("이름", "추가정보", 100);
}