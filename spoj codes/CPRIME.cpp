#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    float n=0.0,lg=0.0,d=0.0,t=0.0,p=0.0;
    cin>>n;
    while(n!=0)
    { 
      t=0;
      lg=log(n);
      //cout<<"\nlg = "<<lg;
      d=n/lg;
      //cout<<"\nd = "<<d<<endl;
                       for(int j=1;j<=n;j++)
                       {        
                             if((j==2)||(j==3))
                             {
                                  t++;
                                  //cout<<j<<endl;
                             }
                             else
                             {
                                 int k=0;
                                 for(int a=2;a<=sqrt(j);a++)
                                 {         
                                    int r=j%a;
                                    if(r==0)
                                    {
                                            k++;
                                            break;
                                    }
                                 }
                                 if((k==0)&&(j!=1))
                                 {       //cout<<j<<endl;
                                         t++;
                                 }
                             }
                     }
                     //cout<<"\nt = "<<t;
                     if(t>d)
                     p=(t-d)*100/t;
                     else
                     p=(d-t)*100/t;
                     printf("%.1f\n",p);
                     cin>>n;
    }
    getch();
    return 0;
}
    
