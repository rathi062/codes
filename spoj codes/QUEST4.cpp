
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
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

const int INF = 0x7fffffff;
const int MAXN = 121, MAXE = 14411;
bool ch[MAXE];
int edge[MAXE][2];
vector<int> job[2*MAXN];
int bipartite(int n)
{
	int idx,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(ch[i]) continue;
		else
		{
			//cout<<"\nedge  = "<<i;
			cnt++;
			idx=( job[edge[i][0]][0] > job[edge[i][1]+121][0] ) ? edge[i][0]:edge[i][1]+121;
			int sz=job[idx].size();
			for(int j=1;j<sz;j++)
			{
				if(ch[job[idx][j]]) continue;
				else
				{
					ch[job[idx][j]]=1;
					job[edge[job[idx][j]][0]][0]--;
					job[edge[job[idx][j]][1]+121][0]--;
				}
			}
		}
	}
	return cnt;
}
int main() {
    int n, e, u, v, c, i,t;
    inp(t);
    while(t--)
    {
    	inp(n);
    	CLR(ch);
		CLR(job);
		for(i=0;i<242;i++)
		job[i].push_back(0);
		CLR(edge);
   		for(i=0; i<n; i++) 
		{
   			inp(edge[i][0]);
   			inp(edge[i][1]);
   			job[edge[i][0]].push_back(i);
   			job[edge[i][0]][0]++;
   			job[edge[i][1]+121].push_back(i);
			job[edge[i][1]+121][0]++;	
    	}
    	//for(i=0;i<=240;i++)
    	//cout<<"\ni = "<<i<<" job = "<<job[i][0];
    	printf("%d\n", bipartite(n));
	}
	return 0;
}
