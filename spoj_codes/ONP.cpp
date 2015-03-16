#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            string s,k;
            cin>>s;
            //cout<<"\nsize of string is : "<<s.size();
            char a[400];
            int p=0;
            for(int j=0;j<s.size();j++)
            {
                    if(s[j]=='(')
                    {continue;}
                    if(s[j]=='+'||s[j]=='/'||s[j]=='*'||s[j]=='-'||s[j]=='^')
                    {a[p++]=char(s[j]);}
                    else
                    {
                        if(s[j]==')')
                        {cout<<a[--p];}  
                        else
                        {cout<<s[j];}
                    }
            }
            while(p!=0)
            cout<<a[--p];
            cout<<endl;
    }
    getch();
    return 0;
}
