#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string s;
    int c=0;
    for(int i=0;i<5;i++)
    {
            cin>>s;
            
            for(int j=0;j<s.size();j++)
            {
                    if(s[j]=='F'&&s[j+1]=='B'&&s[j+2]=='I')
                    {
                          cout<<i+1<<" ";
                          c=1;
                    }
            }
    }
    if(c==0)
    cout<<"HE GOT AWAY!";
    getch();
    return 0;
}
