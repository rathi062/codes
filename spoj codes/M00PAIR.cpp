#include<iostream>
#include<sstream>
#include<stdio.h>
  #include<vector>
  #include<set>
  #include<map>
  #include<queue>
  #include<stack>
  #include<string>
  #include<algorithm>
  #include<functional>
  #include<iomanip>
  #include<cstdio>
  #include<cmath>
  #include<cstring>
  #include<cstdlib>
  #include<cassert>
#define R return
#define FR(i,a,b) for(int i=a;i<b;i++)
#define IN(i,j) a[i][j]
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define inp(x) scanf("%d",&x)
#define getcx getchar_unlocked
using namespace std;
 /*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
string sub(string s,int n)
{
    int l,a,c=0,i,no=0,j=0;
    l=s.size();
    for(i=l-1;i>=0;i--)
    {
         a=s[i]-48;
         if(j==1)
         {
            if(a==0)
            {
               a=9;
               s[i]=char(a+48);
            }
            else
            {
               a--;
               j=0;
               s[i]=char(a+48);
               break;
            }
         }
         else  
         { 
            if(a>=n)
            {
               a-=n;
               s[i]=char(a+48);
               break;
            }
            else
            {
               a+=10;
               //cout<<"\na= "<<a<<end;;
               a-=n;
               s[i]=char(a+48);
               j=1;
            }
         }
    }
    return s;
}
string add(string s,int c)
{
    int l,a,i,no=0,j=0;
    l=s.size();
    for(i=l-1;i>=0;i--)
    {
         a=s[i]-48;
         a+=c;
         s[i]=char(a%10+48);
         c=a/10;
         if(c==0)
         break;
    }
    if(c!=0)
    {
          stringstream out;
          out<<c<<s;
          out>>s;
    }
    return s;
}
void display(string s)
{
     int i=0,l=s.size();
     for(;i<l;i++)
     cout<<s[i];
}       
int main()
{
    string b,s[1001],ar;
    int n;
    queue<int> v;
    while(inp(n))
       v.push(n);
    s[0]="0";
    s[1]="0";
    s[2]="1";
    for(int k=3;k<1001;k++)
    {
       n=1;
       int l,a,c=0,i;
       s[k]=s[k-1];
       l=s[k].size();
       for(i=l-1;i>=0;i--)
       {
         a=s[k][i]-48;
         a*=2;
         a+=c;
         s[k][i]=char(a%10+48);
         c=a/10;
       }
       if(c!=0)
       {
          stringstream out;
          out<<c<<s[k];
          out>>s[k];
       }
       if(k%2==0)
       s[k]=add(s[k],1);
       else
       s[k]=sub(s[k],1);   
       //display(s[k]);
    }
    while(!v.empty())
    {
        display(s[v.front()]);
        printf("\n");
    }
    
//    getch();
    return 0;
}
        
