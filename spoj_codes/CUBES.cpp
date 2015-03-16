#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long sum=0;
    for(int i=2;i<=100;i++)
    {
            long f=i*i*i,n=0;
            for(int j=2;j<i;j++)
            {
                    for(int k=j;k<i;k++)
                    {
                            for(int l=k;l<i;l++)
                            {
                                    n=l*l*l+k*k*k+j*j*j;
                                    if(n>f)
                                    break;
                                    else
                                    if(n==f)
                                    cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")\n";
                            }
                    }
            }
    }
    getch();
    return 0;
}
