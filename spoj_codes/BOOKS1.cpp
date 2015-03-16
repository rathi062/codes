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
#define SET(p) memset(p,-1,sizeof(p))
#define ALL(p) p.begin(),p.end()
#define CLR(p) memset(p,0,sizeof(p))
#define FILL(p,v) memset(p,v,sizeof(p))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(p,b) make_pair(p,b)
#define min3(p,b,c) min(p,min(b,c))
#define max3(p,b,c) max(p,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL unsigned
#define MX 505
#define MAX 1000001
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
struct scriber{
	int st,ed,sum;
}node[MX];
int p[MX];

int main()
{
	int t,n,to,from,k,min;
	inp(t);
	while(t--)
	{
		min=0;
		inp(n);
		inp(k);
		for(int i=0;i<n;i++)
		inp(p[i]);
		for(int i=0;i<k-1;i++)
		{
			node[i].st=i;
			node[i].ed=i;
			node[i].sum=p[i];
			if(node[i].sum>min)
			min=node[i].sum;
		}
		node[k-1].st=k-1;
		node[k-1].ed=n-1;
		node[k-1].sum=0;
		for(int i=k;i<n;i++)
		node[k-1].sum+=p[i];
		if(node[k-1].sum>min)
		min=node[k-1].sum;
		while(1)
		{
			to=k-2;
			from=k-1;
			if(node[to].sum+p[node[from].st]>node[from].sum-p[node[from].st])
			break;
			for(int i=0;i<k-1;i++)
			{
				while(1)
				{
					if(node[to].sum+p[node[from].st]<=node[from].sum-p[node[from].st])
					{
						node[to].sum+=p[node[from].st];
						node[from].sum-=p[node[from].st];
						node[to].ed++;
						node[from].st++;
					}
					else
					{
						to--;
						from--;
						break;
					}
				}
			}
		}
		for(int i=0;i<k;i++)
		{
			for(int j=node[i].st;j<=node[i].ed;j++)
			{
				printf("%d ",p[j]);
			}
			printf("/ ");
		}
		cout<<endl;
	}
	return 0;
}
