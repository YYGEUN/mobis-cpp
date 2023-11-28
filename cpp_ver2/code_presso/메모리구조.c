#include <stdio.h>
int g;
void fn1()
{
    int a;
    int b;
}
void fn2()
{
    int c;
    int d;
    fn1();
}

int main()
{
    int e;
    int f;
    fn2();

    return 0;
}