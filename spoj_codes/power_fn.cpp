#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    double i=0,a=100,p=165465484;
    
    i=modf(a,p);
    printf("%d",&i);
    getch();
    return 0;
}
