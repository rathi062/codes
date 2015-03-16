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
#define MX 100005
#define MOD 1000000007

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
struct Node{
    int min,max;
}nod[MX*4],tp;
int a[MX];
void build(int idx,int st,int ed)
{
	if(st==ed)
	{
		nod[idx].max=nod[idx].min=a[st];
		//cout<<"idx = "<<idx<<" min = "<<nod[idx].min<<" max = "<<nod[idx].max<<endl;
		return ;
	}
	int mid=(st+ed)/2,lft=idx<<1,rgt=lft+1;
	build(lft,st,mid);
	build(rgt,mid+1,ed);
	nod[idx].min=min(nod[lft].min,nod[rgt].min);
	nod[idx].max=max(nod[lft].max,nod[rgt].max);
	//cout<<"idx = "<<idx<<" min = "<<nod[idx].min<<" max = "<<nod[idx].max<<endl;
}
Node query(int idx,int st,int ed,int s,int e)
{
	//cout<<"idx = "<<idx<<endl;
	if(st==s&&ed==e)
	{
		return nod[idx];
	}
	int mid=(st+ed)/2,lft=idx<<1,rgt=lft+1;
	if(e<=mid)
	return query(lft,st,mid,s,e);
	else if(s>mid)
	return query(rgt,mid+1,ed,s,e);
	else
	{
		Node l,r,tmp;
		l=query(lft,st,mid,s,mid);
		r=query(rgt,mid+1,ed,mid+1,e);
		tmp.min=min(l.min,r.min);
		tmp.max=max(l.max,r.max);
		return tmp;
	}
}
int main()
{
    int c, n, i, q, cnt=0, st, ed,val,w,t;
    inp(c);
    while(c--)
    {
      	inp(n);
    	for(i=1;i<=n;i++)
            inp(a[i]);
	   	build(1,1,n);
	   	inp(q);
	   	for(i=0;i<q;i++)
	   	{
	   		inp(st);
	   		inp(ed);
	   		tp=query(1,1,n,st,ed);
	   		printf("%d %d\n",tp.min,tp.max);
	   	}
    }
    return 0;
}


