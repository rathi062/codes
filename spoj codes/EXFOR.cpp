#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,a[10],j=0,k=0,l=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int r=0,ex=0;
            for(j=0;j<10;j++)
            cin>>a[j];
            for(j=0;j<10;j++)
            {
                for(k=j+1;k<10;k++)
                {
                    for(l=k+1;l<10;l++)
                    {
                       if(a[k]==1||a[j]==1||a[l]==1)
                       r=1;
                       else
                       r=0;
                       if(ex==r)
                       ex=0;
                       else
                       ex=1;
                    }
                    if(a[j]==1||a[k]==1)
                    r=1;
                    else
                    r=0;
                    if(ex==r)
                    ex=0;
                    else
                    ex=1;
                }
            }
            cout<<ex<<endl;
    }
    getch();
    return 0;
}
                                 
