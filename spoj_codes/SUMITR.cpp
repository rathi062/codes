#include<iostream>
#include<conio.h>
using namespace std;
int a[99][99];
int fn(int i,int j ,int n)
{
    int s1=0,s2=0;
    if(i<n)
    {
           s1=a[i][j]+fn(i+1,j,n);
           s2=a[i][j]+fn(i+1,j+1,n);
           if(s1>s2)
           {//cout<<s1<<endl;
           return (s1);}
           else
           {
               //cout<<s2<<endl;
               return (s2); 
            }
    }
    return 0;   
}
int main()
{
    int t=0,n=0,i=0,j=0,sum=0;
    cin>>t;
    for(int k=0;k<t;k++)
    {
            sum=0;
              cin>>n;
              for(i=0;i<n;i++)
              {           
                    for(j=0;j<=i;j++)
                    {
                               cin>>a[i][j];
                    }
              }
                    sum+=fn(0,0,n);
                    cout<<sum<<endl;
    }
    getch();
    return 0;
}
