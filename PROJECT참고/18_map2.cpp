#include <map>
#include <string>
#include <iostream>

// map : std::pair 를 여러개 저장하는 컨테이너 입니다.
//       "정확히는" pair 를 "tree" 라는 자료구조에 보관하는것

int main()
{
	// #1. 아래 m 은 pair<std::string, std::string> 를 여러개 보관하겠다는 의미 입니다.
	std::map<std::string, std::string> m;

	// #2. map에 요소를 넣는 방법 1. std::pair 를 넣기
	std::pair<std::string, std::string> p("mon", "월요일");
	m.insert(p);

	// #3. map에 요소를 넣는 방법 2. [] 연산자 사용
	m["tue"] = "화요일";  // std::pair<std::string, std::string> p("tue", "화요일");
						// 을 넣은 것과 동일합니다.
	
	// 일반적으로 [] 연산자 사용이 쉽기 때문에 많이 사용합니다.
	// 위 코드는 결국 "mon, 월요일"의 쌍을 보관하므로 사전 같아 보입니다.
	// 그래서 map 을 다른 언어에서는 "dictionary" 라고 부르고
	// "mon" 을 key,  "월요일" 을 value 라고 합니다. 흔히 key-value 를 저장한다고 합니다.


	// #4. [] 에 대해서 주의 할점!! => 핵심 입니다!!! 반드시 알아 두세요
	// m[key] 의 결과는 value 가 반환 됩니다.
	auto ret1 = m["mon"]; // "mon" 이라는 키값이 존재하므로 ret1 은 "월요일" 입니다.

	auto ret2 = m["wed"]; // 현재 "wed" 라는 키값이 없습니다. 어떻게 될까요 ?
						// 1. 키값이 없으므로 예외가 발생한다.
						// 2. 이순간 ("wed", "") 의 항목이 추가되고, 빈 문자열이 ret2에 반환된다
						// => 답은 2번 입니다.
						// [key] 연산시 key 값이 없으면 즉시 "(key, value디폴트값)"으로 항목이 추가되고
						// "value 디폴트값" 이 반환 됩니다.

	// #5. 따라서 map 에 키값이 있는지 없는지만 조사할때는

	if ( m["fri"] == "" ) 	// ["fri"] 하는 순간 "키값이 없었다면 생성" 됩니다.
	{						// 따라서 이 코드는 키값이 있는지 없는지의 조사가 아닌
						  	// "fri" 키값에 대한 value 가 "" 인지를 조사한것 입니다.
	}

	// 키값이 없는지 조사할때는 find 멤버 함수로 찾아서 반복자가 end() 와 같은지를 확인해야합니다.
	auto it = m.find("sun");

	if ( it == m.end() ) 
	{
		std::cout << "sun key 없음" << std::endl;
	}
}