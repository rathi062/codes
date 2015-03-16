#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,i=0,n=0,j=0,max=0,num=0,tr=0,in=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
       max=0;
       scanf("%d",&n);
       int a[2000][2];
       for(j=0;j<2000;j++)
       a[j][0]=0;
       for(j=0;j<n;j++)
       {
           scanf("%d",&in);
           if(in<0)
           num=1000-in;
           else
           num=in;
           if(a[num][0]!=1)
           {
              a[num][0]=1;
              a[num][1]=1;
           }
           else
           a[num][1]++;
           if(max<a[num][1])
           {
              tr=in;
              max=a[num][1];
           }
       }
       if(n%2==0)
       {
           if(max>(n/2))
           cout<<"YES "<<tr<<endl;
           else
           cout<<"NO\n";
       }
       else
       {
           if(max>((n+1)/2))
           cout<<"YES "<<tr<<endl;
           else
           cout<<"NO\n";
       }
    }
    getch();
    return 0;
}
