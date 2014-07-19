#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    for(int i=0;i<10;i++)
    {
            int c=1;
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
            if(s[j]=='T'||s[j]=='D'||s[j]=='L'||s[j]=='F')
            c*=2;
            cout<<c<<endl;
    }
    getch();
    return 0;
}
