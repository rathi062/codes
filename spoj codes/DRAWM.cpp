#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=-1;
    cin>>n;
    while(n!=-1)
    {
                int a[n][n];
                int l=0,d=0,i=0,j=0,nw=0,max=0;
                cin>>l;
                for(i=0;i<n;i++)
                {
                      if(max<l)
                      max=l;
                      cin>>nw;
                      d=nw-l;
                      if(d==1)
                      {
                              a[l][i]=47;
                              l++;
                      }
                      else
                      if(d==0)
                      a[l][i]=95;
                      else
                      {
                          l--;
                          a[l][i]=92;
                      }
                }
                if(max<l)
                max=l;
                cout<<"\nmax = "<<max<<endl;
                for(i=max;i>=0;i--)
                {
                   for(j=0;j<n;j++)
                   {
                       if(a[i][j]==47||a[i][j]==95||a[i][j]==92)
                       cout<<char(a[i][j]);
                       else
                       cout<<" ";
                       a[i][j]=0;
                   }
                   cout<<endl;
                }
                cout<<"***\n";
                cin>>n;
    }
    getch();
    return 0;
}            
