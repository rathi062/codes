#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int l=0;
    scanf("%d",&l);
    for(int i=0;i<l;i++)
    {
            string s,last;
            cout<<"\nenter next line ";
            getline(cin,s);
            {
                    cin>>s;
                    cout<<s;
                    if(s=="\n")
                    break;
            }
    }
    getch();
    return 0;
}
