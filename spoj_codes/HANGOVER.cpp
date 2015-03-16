#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    float n=0;
    cin>>n;
    while(n!=0)
    {
                 float sum=0.0,i=2.0;
                 while(!(sum>=n))
                 {
                      sum+=1/i;
                      i++;
                 }
                 cout<<i-2<<" card(s)"<<endl;
                 cin>>n;
    }
    getch();
    return 0;
}
