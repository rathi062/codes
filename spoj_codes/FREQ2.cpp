#include<iostream>
#include<conio.h>
using namespace std;
void quick(int a[],int low ,int high );

int main()
{
    int n,q,k,j;
    
    cin>>n;
    int b[n];
    cin>>q;
    for(int i=0;i<n;i++)
    {
            //cout<<"\nenter no ";
            cin>>b[i];
    }
    cout<<"\nnumber entered ";
    for(int i=0;i<q;i++)
    {
            cin>>j>>k;
            int a[k-j];
            for(int p=j;p<=k;p++)
            {
                    a[p-j]=b[p];
            }
            quick(a,0,k-j+1);
            for(int p=0;p<=k-j;p++)
            {
                    cout<<a[p]<<" ";
            }
            int f=0,max=1,l=-1;
            for(int p=0;p<=k-j;p++)
            {
                    cout<<"\nmax is : "<<max;
                    if(a[p]==l)
                    {
                         f++;
                         l=a[p];
                         if(f>max)
                         max=f;
                         
                    }
                    else
                    {
                        f=1;
                        l=a[p];
                    }
            }
            cout<<max<<endl;
    }
    getch();
    return 0;
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
