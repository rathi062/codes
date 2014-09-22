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
#define MX 1503
#define MOD 100000000

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
string s[MX];
bool root[MX];
vector<int> grf[MX],trees;
LL edges;

int bfs(int idx)
{
    int cnt=0;
    for(int i=0;i<grf[idx].size();i++)
    {
        cnt+=bfs(grf[idx][i]);
    }
    edges+=cnt-grf[idx].size();
    cnt++;
    return cnt;
}

int main()
{
    int n;
    inp(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    CLR(root);
    edges=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;i++)
            if(s[i][j]=='1')
                grf[i].PB(j);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='1')
            {
                root[i]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!root[i])
        {
            trees.PB(bfs(i));
        }
    }
    return 0;
}
