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
    int t=0,n=0,k=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int min=1000;
            cin>>n>>k;
            
            int a[n];
             for(int j=0;j<n;j++)
             {
                    cin>>a[j];
             }
             if(k==1)
            {       min=0;  }
            else
            {
             quick(a,0,n);
             for(int i=0;i<(n-k);i++)
             {
                    if((a[i+k]-a[i])<min)
                    min=(a[i+k]-a[i]);
             }
            }
           cout<<min<<endl;
    }
    getch();
    return 0;
}
