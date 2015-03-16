#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=1;
    cin>>n;
    while(n!=0)
    {
               int c=1,i=0;
               
               while(c<n)
               {
                               i++;
                               c+=pow(2,i);
               }
               cout<<i<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
