#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
             
            float sum=0,n=0;
            cin>>n;
            for(int j=1;j<=n;j++)
            {
                    sum+=n/j;
            }
            printf("%.2f",sum);
            cout<<endl;
    }
    getch();
    return 0;
}
                    
