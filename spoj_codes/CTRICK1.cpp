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
#define MX 100000
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


using namespace std;
int r[MX],seg[MX],tree[4*MX];
void init(int idx,int st,int ed)
{
	if(st==ed) 
	{
		tree[idx]=1;
		return ;
	}
	int lft=idx<<1,rgt=lft+1;
	int mid=(st+ed)>>1;
	init(lft,st,mid);
	init(rgt,mid+1,ed);
	tree[idx]=tree[lft]+tree[rgt];
}
int indx(int idx,int st,int ed,int n)
{
	//cout<<"\nst = "<<st<<" ed = "<<ed;
	if(st==ed)
	{
		return st;
	}
	int lft=idx<<1,rgt=lft+1;
	int mid=(st+ed)>>1;
	if(n<=tree[lft]) return indx(lft,st,mid,n);
	return indx(rgt,mid+1,ed,n-tree[lft]);
}
void book(int idx,int st,int ed,int n)
{
	//cout<<"\nst = "<<st<<" ed = "<<ed<<" idx = "<<idx<<" tree[idx] = "<<tree[idx];
	if(st==ed)
	{
		tree[idx]=0;
		return ;
	}
	int lft=idx<<1,rgt=lft+1;
	int mid=(st+ed)>>1;
	if(n<=mid) book(lft,st,mid,n);
	else book(rgt,mid+1,ed,n);
	tree[idx]=tree[lft]+tree[rgt];
}
int main()
{
    int t,n,total,lst,idx,p,val,tmp,lft;
    for(int i=1;i<=MX;i++)
    seg[i]=i;
	inp(t);
    while(t--)
    {
       inp(n);
       init(1,1,n);
       lst=1;
       for(int i=1;i<=n;i++)
       {
       	   total=tree[1];
       	   if(lft>=i+1) 
       	   idx=lst+i;
       	   else
       	   {
       	   		idx=(i+1-lft)%total;
       	   		if(idx==0)
       	   		idx=total;
       	   }
       	   //cout<<"\ni = "<<i<<" idx = "<<idx<<" total "<<total;
       	   r[i]=indx(1,1,n,idx);
       	   lst=idx;
       	   lft=total-idx;
		   //cout<<"\nr[i] = "<<r[i];
       	   seg[r[i]]=i;
			  book(1,1,n,r[i]);
       	   //cout<<endl;
       }
	   for(int i=1;i<=n;i++)
	   printf("%d ",seg[i]);
	   printf("\n");
    }
    return 0;
}
