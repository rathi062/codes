#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int l=0;
    cin>>l;
    while(l!=0)
    {
               printf("%.2f",(l*l)/(2*3.14159265358));
               cout<<endl;
               cin>>l;
    }
    getch();
    return 0;
}
