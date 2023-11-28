#include <stdio.h>
#include <iostream>
using namespace std;

// strcopy 함수를 만드시오
template <typename T, typename U>
decltype(auto) strCopy(T t, U u) {
	return t + u;
}



// int arr[5] = {1,2,3,4,5};     myfilter 함수를 만드시오(람다 사용)
// 3과 같은것, 4이상인것, 3미만인것


void myfilter(int* x, int n, bool(*cmp)(int, int)) {
	
	for (int i = 0; i < 5; i++) {
		if (cmp(x[i], n)) {
			cout << x[i] << " ";
		}
	}
}

void main() {
	cout << strCopy<string,string>("abc", "def") << endl;
	int arr[5] = { 1,2,3,4,5 };
	myfilter(arr, 3, [](int a, int b)->bool {return a > b; });

}