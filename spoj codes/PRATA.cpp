#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
           int p=0,c=0,sum=0,min=8,j=0,ts=0,k=0;
           cin>>p>>c;
           int a[c];
           for( j=0;j<c;j++)
           {       
            cin>>a[j];
            if(a[j]<min)
            min=a[j];
           }
           cout<<"\nmin = "<<min;
           cout<<"\nk = "<<k<<"\nts = "<<ts;
           while(sum<p)
           {
                        //cout<<"\nk = "<<k<<"\nts = "<<ts;
                        //ts=(k*min*(1+k))/2;
                        k++;
                        sum=0;
                        for( j=0;j<c;j++)
                        {
                                sum+=(-a[j]+sqrt(a[j]*a[j]+8*a[j]*k))/(2*a[j]);
                                //cout<<"\nsum = "<<sum;
                        }
                        
           }
           cout<<endl<<k<<endl;
    }
    getch();
    return 0;
}
            
