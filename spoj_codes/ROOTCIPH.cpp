#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            long a,b,c;
            scanf("%ld%ld%ld",&a,&b,&c);
            cout<<(c*c-2*b)<<endl;
    }
    getch();
    return 0;
}
            
