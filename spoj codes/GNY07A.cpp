#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,i=0;
    cin>>t;
    string s="";
    for(i=0;i<t;i++)
    {
                    int p=0;
                    cin>>p;
                    cin>>s;
                    cout<<(i+1)<<" ";
                    for(int j=0;j<s.size();j++)
                    {
                            if(j+1!=p)
                            cout<<s[j];
                    }
                    cout<<endl;
    }
    getch();
    return 0;
}
                    
