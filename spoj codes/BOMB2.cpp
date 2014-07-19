#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0;
    cin>>n>>m;
    while(n!=0&&m!=0)
    {
       int x[n],y[n],bs,bp,s[m];   
       char c[n];
       for(int i=0;i<n;i++)
       {    
            c[i]='n';
            cin>>x[i]>>y[i];
       }
       for(int i=0;i<m;i++)
       {
               s[i]=0;
               cin>>bs>>bp;
               if(bs==0)
               {
                           for(int j=0;j<n;j++)
                           {
                                   if(x[j]==bp)
                                   {
                                       if(c[j]=='n')
                                       {s[i]++;
                                        c[j]='y';}
                                   }
                           }
               }
               if(bs==1)
               {
                           for(int j=0;j<n;j++)
                           {
                                   if(y[j]==bp)
                                   {
                                       if(c[j]=='n')
                                       {s[i]++;
                                        c[j]='y';}
                                   }
                           }
               }
               cout<<s[i]<<endl;
       }
       cout<<endl;
       cin>>n>>m;
    }
    getch();
    return 0;
}
