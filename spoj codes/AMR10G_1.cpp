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
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,k=0;
            cin>>n>>k;
            int a[n];
            for(int j=0;j<n;j++)
            cin>>a[j];
            quick(a,0,n);
            if((a[k-1]-a[0])<(a[n-1]-a[n-k]))
            cout<<(a[k-1]-a[0]);
            else
            cout<<(a[n-1]-a[n-k]);
            cout<<endl;
    }
    getch();
    return 0;
}
