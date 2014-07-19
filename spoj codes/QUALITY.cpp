#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0,d=0,e=0,f=0,s=0,r=1;
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
    {
            int fl=0,t=0,i=1;
            s=3;
            if(a==0)
            s--;
            else
            fl+=d-1;
            if(b==0)
            s--;
            else
            fl+=e-1;
            if(c==0)
            s--;
            else
            fl+=f-1;
            t=fl*20*60+a+b+c;
            cout<<"team "<<i<<": "<<s<<", "<<t<<endl;
            i++;
    }
    getch();
    return 0;
}
    
    
