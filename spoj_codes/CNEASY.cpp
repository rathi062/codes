#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void quick(float a[],int low ,int high )
{
     int k,c,i;
     float sv;
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
            int n=0;
            cin>>n;
            float a[n],d=0.0,max=0.0;
            string s;
            for(int j=0;j<n;j++)
            cin>>s>>a[j];
            quick(a,0,n);
            max=360-a[n-1]+a[0];
            for(int j=0;j<n-1;j++)
            {
                    if((a[j+1]-a[j])>max)
                    max=a[j+1]-a[j];
            }
            d=(360.0-max)*12;
            cout<<ceil(d)<<endl;
    }
    getch();
    return 0;
}
