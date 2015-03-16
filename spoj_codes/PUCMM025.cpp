#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
int main()
{
    string  n; 
    while(!getline(cin,n).eof())
    {
        int l=0;
        l=n.size();
        int t=0,sum=0,num[10],la=0,sl=0,tl=0;
        for(int i=0;i<10;i++)
        num[i]=0;
        for(int i=0;i<l;i++)
        {
                stringstream sm;
                sm<<n[i];
                sm>>t;
                sum+=t;
                num[t]++;
        }
        stringstream last,snd,tr;
        last<<n[l-1];
        last>>la;
        snd<<n[l-2];
        snd>>sl;
        sl=sl*10+la;
        tr<<n[l-3];
        tr>>tl;
        tl=tl*100+sl;
        t=0;
        //cout<<la<<endl<<sl<<endl<<tl<<endl<<sum<<endl<<t;
        int p=0,q=0,r=0,s=0;
        for(int i=1;i<10;i++)
        {
                if(num[i]!=0)
                {
                     switch(i)
                     {
                         case 1:
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];
                              break;
                              
                         case 2:
                              if(la%2==0)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                              
                         case 3:
                              if(sum%3==0)
                              t+=num[i];
                              break;
                              
                         case 4:
                              if(sl%4==0)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                              
                         case 5:
                              if(la==0||la==5)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                              
                         case 6:
                              if(la%2==0&&sum%3==0)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                              
                         case 7:
                               r=0;
                               q=0;
                               s=0;
                              for( p=0;p<l;p++)
                              {
                                      stringstream out;
                                      out<<n[p];
                                      out>>s;
                              //        cout<<"\ns = "<<s;
                                      q=r*10+s;
                                      r=q%7;
                              }
                              if(r==0)
                              t+=num[i];
                              break;
                              
                         case 8:
                              if(tl%8==0)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                              
                         case 9:
                              if(sum%9==0)
                              t+=num[i];
                              //cout<<"\nnum is "<<num[i];}
                              break;
                     }
                }
        }
        cout<<t<<endl;
    }
    getch();
    return 0;
}
