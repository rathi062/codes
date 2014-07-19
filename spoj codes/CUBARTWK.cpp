#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int f=0,r=0,sum=0;
    cin>>f>>r;
    do
    {
                     int a[f];
                     int b[r];
                     sum=0;
                     
                     for(int i=0;i<f;i++)
                     {cin>>a[i];}
                     for(int i=0;i<r;i++)
                     {cin>>b[i];}
                     for(int i=0;i<f;i++)
                     {
                             for(int j=0;j<r;j++)
                             {
                                     if(a[i]==b[j])
                                     {
                                            b[j]=0;
                             
                                            break;
                                     }
                             }
                             
                             sum=sum+a[i];
                             
                     }
                     for(int j=0;j<r;j++)
                     {
                             
                             sum=sum+b[j];}
                     cout<<sum<<endl;
                     cin>>f>>r;
    }while(f!=0||r!=0);
    getch();
    return 0;
}    
