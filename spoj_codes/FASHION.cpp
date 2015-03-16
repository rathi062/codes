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
    int n,t;
    cout<<"no of test cases : ";
    cin>>t;
    for(int k=0;k<t;k++)
   {
    cout<<"\nenter the no of particepent  : ";
    cin>>n;
    int a[n],b[n],s=0;
    
            for(int i=0;i<n;i++)
            {
                    cin>>a[i];
            }
            
            for(int i=0;i<n;i++)
            {
                    cin>>b[i];
            }
    quick(a,0,n);
    quick(b,0,n);
    for(int i=0;i<n;i++)
    {
            a[i]=a[i]*b[i];
            s+=a[i];
    }
    cout<<"\nsum is : "<<s;
   }
    getch();
    return 0;
}
