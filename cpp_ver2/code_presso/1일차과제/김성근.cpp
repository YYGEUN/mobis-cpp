#include <stdio.h>
#include <iostream>
using namespace std;


void mystrcpy(char* des, const char* src);

void main()
{
	cout << "HELLO" << endl;
	char Des[50];
	

	mystrcpy(Des, "abcd");
	cout << "Ãâ·Â" << Des <<endl;
}


void mystrcpy(char* des, const char* src)
{
	int cnt = 0;

	while (*(src+cnt) != NULL) { 
		des[cnt] = src[cnt];
		cnt++;
	}

	des[cnt] = '\0'; 

}

