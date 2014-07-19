#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            float r;
            cin>>r;
            
            printf("%.2f\n",((1.0/4.0)+(4.0)*r*r));
    }
    getch();
    return 0;
}
