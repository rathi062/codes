#include<iostream>
#include<conio.h>
#include<iomanip.h>
using namespace std;
int main()
{
    int n,a=2,b=3;
    cin>>n;
    float  sum;
    sum=(a/b)*1.0;
    cout<<sum;
    for(int i=2;i<=n;i++)
    {
            sum+=(1/(i*(i+1)*(i+2)));
    }
    //printf("%.11f",sum);
    getch();
    return 0;
}
