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
#define cls(a) memset(a,-1,sizeof(a))
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
#define MX 5003
#define MOD 1000000007

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
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
struct topo_sort{
	int in,fin,str;
}lst[MX];
struct edge{
	int s,d;
}ed[MX];
bool check[MX],inlist[MX],sink[MX],vld[MX];
vector<int> grf[MX],inv_grf[MX],grpno[MX];
int ver[MX], per[MX],st[MX],f[MX],v,e,s,d,tm,idx;
void initial(int n)
{
	for(int i=1;i<=n;i++)
	{
		per[i]=0;
		ver[i]=INF;
		check[i]=0;
		inlist[i]=0;
		sink[i]=0;
		grf[i].clear();
		inv_grf[i].clear();
		grpno[i].clear();
		vld[i]=0;
	}
}
void DFS_visit(int n)
{
	idx++;
	tm++;
	st[n]=tm;
	int odr=idx;
	lst[odr].str=tm;
	check[n]=1;
	int l=grf[n].size();
	for(int i=0;i<l;i++)
	{
		if(check[grf[n][i]]==0)
		{
			DFS_visit(grf[n][i]);
		}
	}
	tm++;
	f[n]=tm;
	lst[odr].in=n;
	lst[odr].fin=tm;
}

void DFS()
{
	tm=idx=0;
	DFS_visit(s);
	for(int i=1;i<=v;i++)
	{
		if(check[i]==0)
		{
			DFS_visit(i);
		}
	}
}

int compare(const topo_sort a,const topo_sort b)
{
	return ((a.fin==b.fin)?(a.in<b.in):(a.fin>b.fin));
}
void DFS_visit_inv(int n,int no)
{
	inlist[n]=1;
	grpno[no].PB(n);
	per[n]=no;
	int l=inv_grf[n].size();
	for(int i=0;i<l;i++)
	{
		if(inlist[inv_grf[n][i]]==0)
		{
			DFS_visit_inv(inv_grf[n][i],no);
		}
	}
}

void DFS_inv()
{
	tm=idx=0;
	int no=1;
	for(int i=1;i<=v;i++)
	{
		if(inlist[lst[i].in]==0)
		{
			//cout<<"\nroot is = "<<lst[i].in ;
			DFS_visit_inv(lst[i].in,no++);
		}
	}
}
int main()
{
	inp(v);
	while(v!=0)
	{
	
	inp(e);
	initial(v);
	for(int i=0;i<e;i++)
	{
		inp(ed[i].s);
		inp(ed[i].d);
		grf[ed[i].s].push_back(ed[i].d);
		inv_grf[ed[i].d].push_back(ed[i].s);
	}
	s=1;
	DFS();
	sort(lst+1,lst+v+1,compare);
	DFS_inv();
	s=1;
	/*for(int i=1;i<=v;i++)
	cout<<per[i]<<" ";
	cout<<endl;*/
	for(int i=1;i<=v;i++)
	{
		int sz=grf[i].size();
		for(int j=0;j<sz;j++)
		{
			if(per[i]!=per[grf[i][j]])
			{
				sink[per[i]]=1;
				break;
			}
		}
	}
	
	for(int i=1;i<=v;i++)
	if(!sink[per[i]])
	printf("%d ",i);
	cout<<endl;
	inp(v);
	
	}
	return 0;
}
