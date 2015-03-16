#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    while(n!=0)
    {
               string s;
               cin>>s;
               int z=0,size=0,c=0,t=0;
               size=s.size();
               cout<<size<<endl;
               z=size/n;
               char ch[z][n];
               for(int i=0;i<z;i++)
               {
                       if(t%2==0)
                       {
                           t++;
                           for(int j=0;j<n;j++)
                           {
                               ch[i][j]=s[i*n+j];
                           }
                       }
                       else
                       {
                           t++;
                           for(int j=n-1,c=0;j>=0;j--,c++)
                           {
                               ch[i][j]=s[i*n+c];
                           }
                       }
               }
               for(int i=0;i<n;i++)
               {
                       for(int j=0;j<z;j++)
                       {
                               cout<<ch[j][i];
                       }
               }
               cout<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
