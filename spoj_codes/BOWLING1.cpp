#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int a=0,b=0,c=0,sum=0,r=0,k=0;
            for(int j=0;j<10;j++)
            {
                    if(j==9)
                    {
                         cin>>a>>b;
                         if(r==1)
                         sum+=a;
                         if(k==1)
                         sum+=(10+a+b);
                         if(k==2)
                         sum+=(10+a);
                         if(a==10||(a+b)==10)
                         {
                                   cin>>c;
                                   sum+=(a+b+c);
                         }
                         else
                         sum+=(a+b);   
                    }
                    else
                    {
                        cin>>a;
                        if(k==2)
                        {
                                sum+=(10+a);
                                k=0;
                        }
                        if(r==1)
                        {
                            sum+=a;
                            r=0;
                        }
                        if(a!=10)
                        {
                                 cin>>b;
                                 if(k==1)
                                 {
                                         sum+=(10+a+b);
                                         k=0;
                                 }
                                 if((a+b)!=10)
                                 {
                                     sum+=(a+b);
                                 }
                                 else
                                 k=2;
                        }
                        else
                        {
                            if(k==1)
                            {
                                sum+=20;
                                r=1;
                            }
                            k=1;
                        }
                    }
                    //cout<<"\nsum is : "<<sum;
            }
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
            
            
            
