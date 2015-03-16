#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    while(n!=0)
    {
               int  a[n],num=n;
               for(int i=0;i<n;i++)
               cin>>a[i];
               for(int i=0;i<n-1;i++)
               {
                       int k=i,sum=0;
                       for(int j=0;j<n;j++,k++)
                       {
                               sum+=a[k];
                               if(sum<0)
                               {
                                  num--;
                                  break;
                               }
                               if((k)==(n-1))
                               k=0;
                       }
               }
               cout<<num<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
