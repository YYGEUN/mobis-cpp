#include <stdio.h>
#include <iostream>

using namespace std;

/*1. mystrcopy 함수 만들기
  char s[50];
  mystrcopy(s, "abcd");
  printf("%s\n", s); 했을 때 abcd가 출력되게 */
void myStrcpy(char* str, const char* target) {
	int idx = 0;
	while (*target != NULL) {
		str[idx] = *target;
		idx++;
		target++;
	}
	
}

/*2. int arr[5] = {1, 2, 3, 4, 5};
  myfilter 함수를 만드시오 (람다식 활용)
  ex. 3과 같은 것 */
void myFilter(int* arr, int size, bool (*cmp)(int)) {
	for (int i = 0; i < size; i++) {
		if (cmp(arr[i])) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

int main() {
	
	cout << "━━  1번 문제" << endl;
	char s[50] = { 0, };
	myStrcpy(s, "abcd");
	printf("%s\n", s);


	cout << "━━  2번 문제" << endl;
	int arr[5] = { 1, 2, 3, 4, 5 };
	cout << "3 이상인 경우" << endl;
	myFilter(arr, 5, [](int a)->bool {return a >= 3; });
	cout << "2 미만인 경우" << endl;
	myFilter(arr, 5, [](int a)->bool {return a < 2; });

	return 0;
}

