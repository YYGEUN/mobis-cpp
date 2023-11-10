// reference_return.cpp
int x = 0;

int  f1() { return x;}
int& f2() { return x;}

int main()
{
	// 일반적으로 함수의 호출은 "우변" 에 놓게 됩니다.
	int ret = f1();

	// 그런데, 함수 호출이 좌변에 놓이는 경우도 있습니다.
	// v[0] = 10; //  v.operator[](0) = 10    의 원리 입니다.

	// 아래 2줄을 생각해 봅시다.	
	f1() = 10;
	f2() = 10;
}