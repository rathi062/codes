#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            float n;
            cin>>n;
            float a[int(n)][2],sumx=0.0,sumy=0.0;
            for(int j=0;j<n;j++)
            {
                    cin>>a[j][0]>>a[j][1];
                    sumx+=a[j][0];
                    sumy+=a[j][1];
            }
            float x,y;
            printf("%.2f",sumx/n);
            y=sumy/n;
            printf(" %.2f",y);
    }
    getch();
    return 0;
}
