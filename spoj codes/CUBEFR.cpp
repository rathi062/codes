#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    float a=0,b=0,p=(1/3.0);
    int n=0,x=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a;
            cout<<"Case "<<i+1<<": ";
            if(a==1)
            cout<<"1";
            else
            {
                int j=2,sum=0,f=0;
                while(1)
                {
                        p=a/(j*j*j);
                        if(p<1)
                        break;
                        if(p==int(p))
                        {f=1;
                         break;}
                        else
                        {
                            sum+=int(p);
                            j++;
                        }
                }
                if(f==0)
                cout<<(a-sum);
                else
                cout<<"Not Cube Free";
                cout<<endl;
            }
    }
    getch();
    return 0;
}
    
