#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            int k,l,min,max,sum=0;
            cin>>k>>l;
            if(k>l)
            {min=l;
            max=k;}
            else
            {min=k;
            max=l;}
            for(int j=1;j<=min/2;j++)
            {
                    if(k%j==0&&l%j==0)
                    sum++;
            }
            if(max%min==0)
            sum++;
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
