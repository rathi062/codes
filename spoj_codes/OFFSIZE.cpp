#include<iostream>
#include<conio.h>
using namespace std;
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
    int n=0,m=0;
    cin>>n>>m;
    while(n!=0&&m!=0)
    {
                     int a[n],b[m];
                     for(int i=0;i<n;i++)
                     cin>>a[i];
                     for(int i=0;i<m;i++)
                     cin>>b[i];
                     quick(a,0,n);
                     quick(b,0,m);
                     if(a[0]<b[1])
                     cout<<"Y"<<endl;
                     else
                     cout<<"N"<<endl;
                     cin>>n>>m;
    }
    getch();
    return 0;
}
