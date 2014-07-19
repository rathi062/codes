#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF)
    {
            string a,b,f;
            cin>>a>>b;
            int l=0;
            l=sizeof(a);
            size_t found;
            found=b.find(a);
            while(found!=string::npos)
            {
                 cout<<int(found)<<endl;
                 found=b.find(a,found+1);
            }
            cout<<endl;
    }
    getch();
    return 0;
}
            
