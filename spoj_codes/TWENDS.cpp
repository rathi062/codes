#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    while(n!=0)
    {
               int a[n],sum1=0,sum2=0,f=0,r=n-1,m1=0,m2=0;
               for(int i=0;i<n;i++)
               cin>>a[i];
               for(int i=0;i<n;i++)
               {
                       if(i%2==1)
                       {
                            if(a[f]>=a[r])
                            {
                                          cout<<"\np2 selects : "<<a[f];
                                          sum2+=a[f++];
                            }
                            else
                            {
                                cout<<"\np2 selects : "<<a[r];
                                sum2+=a[r--];
                            }
                       }
                       else
                       {
                           if(a[f+1]>a[r])
                           m1=a[f+1];
                           else
                           m1=a[r];
                           if(a[f]>a[r-1])
                           m2=a[f];
                           else
                           m2=a[r-1];
                           cout<<"\nma : "<<m1<<" mb : "<<m2;
                           if((m1-a[f])>(m2-a[r]))
                           {
                                    cout<<"\np1 selects : "<<a[r];
                                    sum1+=a[r--];
                           }
                           else
                           {
                               cout<<"\np1 selects : "<<a[f];
                               sum1+=a[f++];
                           }
                       }
               }
               cout<<(sum1-sum2)<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
