#include<iostream>
#include<conio.h>
using namespace std;
int tree(int [],int ,int);
int main()
{
    int n,min=1000,sum=100;
    cin>>n;
    int a[n],d[n-1];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
            if(i!=0)
            {
                    d[i-1]=a[i]-a[i-1];
                    //cout<<"\nd = "<<d[i-1];
                    if(min>d[i-1])
                    {min=d[i-1];}
                    //cout<<"\nmin is "<<min;
            }
    }
    //cout<<"\nmin is "<<min;
    sum=tree(d,n,min);
    cout<<sum;
    getch();
    return 0;
}
int tree(int d[],int n,int min)
{
    int sum=0,m;
    //cout<<"\nmin is "<<min;
    for(int i=0;i<n-1;i++)
    {
            if(d[i]%min==0)
            {
                   sum+=(d[i]/min)-1;
            }
            else
            {
               m=d[i]%min;
               sum=tree(d,n,m);
               break;
            }
    }
    return sum;
} 
