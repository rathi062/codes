#include<iostream>
#include<conio.h>
using namespace std;
int sum=0;
void fn(int s[],int e[],int in[],int n,int cl,int cm,int end)
{
     if(cm<cl-1)
     {
                for(int i=0;i<n;i++)
                {
                        if(end<=s[i])
                        fn(s,e,in,n,cl,cm+1,e[i]);
                }
     }
     else
     {
         int c=0;
         for(int i=0;i<n;i++)
         {
                 if(in[i]>=end)
                 {c=n-i;
                  break;}
                 
         }
         //cout<<c<<end;
         sum+=c;
     }
}
void quick(int a[],int low ,int high )
{
     int k,c,i,sv;
     k=high-1;
     i=low;
     if(high>low)
     {
        while(i!=k)
        {
           
           if(a[i]>a[k])
           {
              sv=a[i];
              a[i]=a[k-1];
              a[k-1]=a[k];
              a[k]=sv;
              k=(k-1);
           }
           else
           {  i=i+1;  }
        }
        quick(a,low,k);
        quick(a,(k+1),high);
     }
}
               
int main()
{
    int n=0;
    cin>>n;
    while(n!=-1)
    {
         int s[n],e[n],in[n];
         for(int i=0;i<n;i++)
         cin>>s[i]>>e[i];
         sum=0;
         for(int i=0;i<n;i++)
         in[i]=s[i];
         quick(in,0,n);
         
         for(int i=1;i<=n;i++)
         {
                 fn(s,e,in,n,i,0,0);
                 sum=sum%100000000;
         }
         printf("%08d",sum);
         //cout<<sum<<endl;
         cin>>n;
    }
    getch();
    return 0;
}
