#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
   for(int k=0;k<t;k++)
   {
    int n,i,j,temp,swap=0;
    cout<<"enter the no of elts :";
    cin>>n;
    int a[n];
    cout<<"\n\nenter elt\n";
    for(i=0;i<n;i++)
    {
           cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
                    temp=a[i];
                    for(j=i;j>0;--j)
                    {
                                    if(a[j-1]>temp)
                                    {
                                                   a[j]=a[j-1];
                                                   swap++;
                                    }
                                    else
                                    break ;
                    }
                    a[j]=temp;
                                                  
    }
    cout<<swap<<endl;
   }
    getch();
    return 0;
}

