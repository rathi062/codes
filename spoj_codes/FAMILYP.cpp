#include<iostream>
 
#include<math.h>
using namespace std;
int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF)
    {
            int r=0,m=0,row=0,clm=0;
            char ch;
            r=(-1+sqrt(1+8*n))/2;
            if(r*(r+1)/2==n)
            {
                            if(r%2==0)
                            {
                                      row=r%26;
                                      clm=1;
                                      ch=char(64+(row+clm)%26-1);
                                      cout<<"TERM "<<n<<" IS "<<ch<<endl;
                            }
                            else
                            {
                                      row=1;
                                      clm=r%26;
                                      ch=char(64+(row+clm)%26-1);
                                      
                                cout<<"TERM "<<n<<" IS "<<ch<<endl;
                            }
            }
            else
            {
                m=n-(r*(r+1)/2);
                if(r%2==0)
                {
                          row=(r-m+2)%26;
                          clm=m%26;
                          ch=char(64+(row+clm)%26-1);
                          
                          cout<<"TERM "<<n<<" IS "<<ch<<endl;
                }
                else
                {
                    row=m%26;
                          clm=(r-m+2)%26;
                          ch=char(64+(row+clm)%26-1);
                          
                    cout<<"TERM "<<n<<" IS "<<ch<<endl;
                }
            }
    }
 
    return 0;
}
