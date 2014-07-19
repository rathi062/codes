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
void quickb(int b[],int low ,int high )
{
     int k,c,i,sv;
     k=high-1;
     i=low;
     if(high>low)
     {
        while(i!=k)
        {
           
           if(b[i]>b[k])
           {
              sv=b[i];
              b[i]=b[k-1];
              b[k-1]=b[k];
              b[k]=sv;
              k=(k-1);
           }
           else
           {  i=i+1;  }
        }
        quickb(b,low,k);
        quickb(b,(k+1),high);
     }
}
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,c=0,p=0,q=0,max=0;
            cin>>n;
            int a[n],b[n];
            for(int j=0;j<n;j++)
            cin>>a[j]>>b[j];
            quick(a,0,n);
            quickb(b,0,n);
            for(int j=0;j<2*n;j++)
            {  
              if(p!=(n))
              {
                 if(a[p]<b[q])
                 {
                      c++;
                      p++;
                      if(max<c)
                      max=c;
                 }
                 else
                 {
                     c--;
                     q++;
                 }
              }
            }
            cout<<max<<endl;
    }
    getch();
    return 0;
}
