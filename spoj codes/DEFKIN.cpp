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
            int w=0,h=0,n=0,lx=0,ly=0;
            cin>>w>>h>>n;
            int x[n],y[n];
            for(int j=0;j<n;j++)
            cin>>x[j]>>y[j];
            quick(x,0,n);
            quick(y,0,n);
            lx=x[n-1];
            ly=y[n-1];
            int disx=0,disy=0,maxx=0,maxy=0;
            for(int j=0;j<n-1;j++)
            {
                    disx=x[j+1]-x[j];
                    disy=y[j+1]-y[j];
                    if(maxx<disx)
                    maxx=disx;
                    if(maxy<disy)
                    maxy=disy;
            }
            if(w-lx>maxx)
            maxx=w-lx+1;
            if((h-ly)>maxy)
            maxy=h-ly+1;
            cout<<"\nmaxx = "<<maxx<<"  maxy = "<<maxy<<endl;
            cout<<(maxx-1)*(maxy-1)<<endl;
    }
    getch();
    return 0;
}
            
