#include<iostream>
#include<conio.h>
using namespace  std;
int **c;
int fun(string a[],int h,int w,int in,int x,int y)
{
   if(c[x][y]==0)
   {
     int r=0,m=0;
     if(x>0)
       if(int(a[x-1][y])==in)
       {
          r=fun(a,h,w,in+1,x-1,y);
          if(r>m)
          m=r;
       }
     if(y>0)
       if(int(a[x][y-1])==in)
       {
         r=fun(a,h,w,in+1,x,y-1);
         if(r>m)
         m=r;
       }
     if(x<h-1)
       if(int(a[x+1][y])==in)
       {
          r=fun(a,h,w,in+1,x+1,y);
          if(r>m)
          m=r;
       }
     if(y<w-1)
       if(int(a[x][y+1])==in)
       {  r=fun(a,h,w,in+1,x,y+1);
          if(r>m)
          m=r;
       }
     if(x>0&&y>0)
       if(int(a[x-1][y-1])==in)
       {  r=fun(a,h,w,in+1,x-1,y-1);
          if(r>m)
          m=r;
       }
     if(x>0&&y<w-1)
       if(int(a[x-1][y+1])==in)
       {  r=fun(a,h,w,in+1,x-1,y+1);
          if(r>m)
          m=r;
       }
     if(x<h-1&&y>0)
       if(int(a[x+1][y-1])==in)
       {  r=fun(a,h,w,in+1,x+1,y-1);
          if(r>m)
          m=r;
       }
     if(x<h-1&&y<w-1)
       if(int(a[x+1][y+1])==in)
       {  r=fun(a,h,w,in+1,x+1,y+1);
          if(r>m)
          m=r;
       }
       c[x][y]=m+1;
       return (m+1);
   }
   else
   return (c[x][y]);
}
int main()
{
    int n=0,m=0,r;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
          int mx=0;
          c=new int*[n];
          for(int i=0;i<n;i++)
          {
                  c[i]=new int[m];
                  for(int j=0;j<m;j++)
                  c[i][j]=0;
          }
          string a[n];
          for(int i=0;i<n;i++)
          {
                  cin>>a[i];
          }
          for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          {
            r=fun(a,n,m,65,i,j);
            if(r>mx)
            mx=r;
          }
          cout<<mx<<endl;
          cin>>n>>m;
    }
    getch();
    return 0;
}

