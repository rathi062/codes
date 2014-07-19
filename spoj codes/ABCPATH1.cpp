
#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 51
#define MOD 1000000007

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/

int c[MX][MX];
int fun(string a[],int h,int w,int in,int x,int y)
{
     int r=0,m=0;
     if(c[x][y]!=0)
     return c[x][y];
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
int main()
{
    int n=0,m=0,r,cs=1;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
          int mx=0;
          string a[n];
          CLR(c);
          for(int i=0;i<n;i++)
          {
                  cin>>a[i];
          }
          for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          {
            if(c[i][j]==0)
			{
				r=fun(a,n,m,int(a[i][j])+1,i,j);
				c[i][j]=r;
			}
			else
			r=c[i][j];
            if(a[i][j]=='A')
            {	
				if(r>mx)
				mx=r;
			}
          }
          cout<<"Case "<<cs++<<": "<<mx<<endl;
          cin>>n>>m;
    }
    return 0;
}

