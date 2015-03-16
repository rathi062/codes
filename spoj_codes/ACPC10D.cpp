#include<iostream>
#include<conio.h>
using namespace std;
int fn(int a[][3],int i,int n)
{
    int s1=0,s2=0,s3=0,max=0;
    if(i<n-1)
    {
        s1=a[i][0]+fn(a,i+1,n);
        s2=a[i][1]+fn(a,i+1,n);
        s3=a[i][2]+fn(a,i+1,n);
        if(s1<s2&&s1<s3)
        return s1;
        if(s2<s1&&s2<s3)
        return s2;
        if(s3<s2&&s3<s1)
        return s3;
    }
    else
    return 0;
}
int main()
{
    int n=0;
    cin>>n;
    while(n!=0)
    {
               int a[n][3],s1=0,c=1;
               char ch='.';
               for(int i=0;i<n;i++)
               {
                       cin>>a[i][0]>>a[i][1]>>a[i][2];
               }
               s1=a[0][1]+fn(a,1,n)+a[n-1][1];
               cout<<c<<ch<<" "<<s1;
               c++;
               cin>>n;
    }
    getch();
    return 0;
}
