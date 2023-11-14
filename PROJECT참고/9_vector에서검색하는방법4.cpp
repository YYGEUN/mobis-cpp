#include <vector>
#include <string>
#include <algorithm>

class Appliance
{
	std::string name;
public:	
	Appliance(const std::string& name) : name(name) {}

	std::string get_name() { return name;}
};

int main()
{
	std::vector<Appliance*> v;

	v.push_back( new Appliance("name1"));
	v.push_back( new Appliance("name2"));
	v.push_back( new Appliance("name3"));

	// name2 를 찾은후 그 위치를 가리키는 반복자(포인터)를 얻습니다.
	auto p1 = std::find(v.begin(), v.end(), 
						[](Appliance* p){ return p->get_name() == "name2"; });


	// 이제 name2를 vector 에서 제거합니다.
//	v.erase(p1); // 이렇게 하면 vector 에 있는 포인터만 제거된것이고
				 // new 로 만든 객체 자체가 제거된 것은 아닙니다.
				 // 물로 "스마트 포인터를 사용했다면" 포인터만 제거되면 객체도 제거 됩니다.

	// 스마트 포인터를 사용하지 않았다면 아래 처럼 합니다.
	delete *p1; // p1 의 vector 의 요소를 가리키는 반복자(포인터) 이므로
				// *p1 하면 요소에 접근하게 되는데, 요소 자체가 포인터 이므로 
				// delete *p1 해서 "new 로 만든 객체를 파괴 합니다."	
				// 아래 그림에서 "객체A" 를 파괴 한것						

	v.erase(p1); // v 에서 p1을 파괴 합니다.	
				 // 아래 그림에서 "주소A" 를 vector 에서 제거 한것			
}

//     		        "객체A"
//                    ^         
//                    | 
// v 안에는 : | 주소 | 주소A | 주소 |
//             
