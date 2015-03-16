#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0;
            scanf("%d",n);
            char *s[n];
            int a[n],c[n],k=0,count=0;
            for(int j=0;j<n;j++)
            {
                    scanf("%s",&s[j]);
                    if(s[j]=="declare")
                    {
                       a[j]=1;
                       c[j]=-1;
                       count++;
                    }
                    else
                    {
                        cin>>c[j];
                        a[j]=1;
                        count++;
                        k=c[j];
                        do
                        {
                           if(a[k-1]==1)
                           {
                               a[k-1]=0;
                               count--;
                           }
                           else
                           {
                               a[k-1]=1;
                               count++;
                           }
                           k=c[k-1];
                        }
                        while(k!=(-1));
                    }
                    //cout<<"\ncount is : "<<count;
            }
            printf("%d \n",count);
            for(int j=0;j<n;j++)
            if(a[j]==1)
            cout<<j+1<<" ";
    }
    getch();
    return 0;
}
                           
                               
                    
