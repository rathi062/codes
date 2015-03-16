#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int a[1000],j=0,max=0,num=1,p=0,s=0;
            cin>>num;
            while(num!=0)
            {
                    cout<<"\ngirls way ";
                    a[num]=1;
                    if(num>max)
                    max=num;
                    cin>>num;
            }
            while(1)
            {
                    p=0;
                    int b[1000];
                    cin>>num;
                    if(num==0)
                    break;
                    else
                    {
                        cout<<"\ntom's way ";
                        b[num]=1;
                        while(1)
                        {cin>>num;
                        if(num==0)
                        break;
                        b[num]=1;}
                    }
                    for(int k=1;k<=max;k++)
                    {
                            if(a[k]==1&&b[k]==1)
                            p++;
                    }
                    if(p>s)
                    s=p;
            }                
            cout<<s<<endl;
    }
    getch();
    return 0;
}
