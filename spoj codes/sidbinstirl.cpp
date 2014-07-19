#include<iostream>
# include <conio.h>

using namespace std;

int s(int n,int m)
   {
    if(n==m)
     return 1;
    else
     if(n==0 || m==0)
      return 0;
     else
      if(n<m)
       return 0;
      else
       if(m==1 || m==2)
        return 1;
       else
        return (m*s(n-1,m)+s(n-1,m-1));
   }

int main()
   {
    int d=0,n,m;
    cin>>d;
    while(d--)
     {
      cin>>n>>m;
      cout<<s(n,m)<<"\n";
     }
     getch();
    return 0;
   } 
