#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0,x=0,y=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    cin>>m;
    for(int k=0;k<m;k++)
    {
            cin>>x>>y;
            long long max=-16000,sum=a[x-1];
            for(int i=x-1;i<y;i++)
            {
                    if(sum<0)
                    {
                             if(a[i]>sum)
                             sum=a[i];
                    }
                    else
                    {
                        if(i!=x-1)
                        sum+=a[i];
                        if(sum>max)
                        max=sum;
                    }
            }
            if(sum>max)
            max=sum;
            cout<<max<<endl;
    }
    getch();
    return 0;
}
