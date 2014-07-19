#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=0,b=0,max=0,min=0;
    cin>>a>>b;
    while(a!=0&&b!=0)
    {
        if(a>b)
        {max=a;
        min=b;}
        else
        {max=b;
        min=a;}
        int d=0,c=0;
        for(int i=min;i>0;i--)
        {
                d=max/i;
                c=min/i;
                if(max==(i*d)&&min==(c*i))
                {
                     cout<<(max/i)*(min/i)<<endl;
                     break;
                }
        }
        cin>>a>>b;
    }
    getch();
    return 0;
}
        
    
