#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    int a=0,b=0,c=0,d=0;
    char f[n],s[n],ch[4]={'A','B','C','D'};
    for(int i=0;i<2*n;i++)
    {
            cin>>f[i];
            if(f[i]=='A')
            a++;
            if(f[i]=='B')
            b++;
            if(f[i]=='C')
            c++;
            if(f[i]=='D')
            d++;
    }
    int r[4];
    r[0]=n-a;
    r[1]=n-b;
    r[2]=n-c;
    r[3]=n-d;
    cout<<"remainng a b c d are : "<<r[0]<<r[1]<<r[2]<<r[3]<<endl;
    a=-1;
    for(int i=0;i<2*n;i++)
    {
            int max=0,in=4;
       for(int j=0;j<4;j++)
        {
                    if(f[i]!=ch[j] && j!=a)
                    {
                                   if(r[j]>=max)
                                   {
                                                if(i<(2*n-2))
                                                {
                                                    max=r[j];
                                                     in=j;
                                               
                                               }
                                               else
                                               {
                                                   if(in!=4)
                                                   {
                                                             if(ch[in]!=f[2*n-1])
                                                             {
                                                                   max=r[j];
                                                                   in=j;
                                                             }
                                                   }
                                                   else
                                                   {
                                                       max=r[j];
                                                       in=j;
                                                   }
                                               }
                                   }
                                                             
                                       
                    }
        }
        cout<<ch[in];
        --r[in];
        a=in;
        cout<<"\nremainng a b c d are : "<<r[0]<<r[1]<<r[2]<<r[3]<<endl;
    }
    getch();
    return 0;
}
