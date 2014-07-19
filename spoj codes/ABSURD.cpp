#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
int absurd(int n)
{
    stringstream out;
    string s;
    while(n%10==0)
    {
        n=n/10;
    }
    out<<n;
    out>>s;
    if(n%10==5)
    return ((s.size()*2)-1);
    else
    return (s.size()*2);
}
int main()
{
    int n=0,num=0,abs=0,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            int c=0;            
            cin>>num;
            while(num%10==0)
            {
                  num=num/10;
            }
            //cout<<num<<endl;
            abs=absurd(num);
            //cout<<abs;
            for(int j=(num*95)/100;j<=(num*105)/100;j++)
            {
                    k=absurd(j);
                    if(k<abs)
                    {
                             cout<<"absurd\n";
                             c++;
                             break;
                    }
            }
            if(c==0)
            cout<<"not absurd\n";
    }
    getch();
    return 0;
}
