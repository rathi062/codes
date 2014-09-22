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
bool check[MX];
vector<int> a;
int main()
{
    int n=0,no;
    inp(n);
    for(int i=0;i<n;i++)
    {
        inp(no);
        a.PB(no);
    }
    vector<int > v;
    v.assign(a.begin(),a.end());
    sort(v.begin(),v.end());
//    for(int i=0;i<v.size();i++)
//        cout<<v[i]<<" ";
//    cout<<endl;
    int p=-1,q;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=v[i])
        {
            p=i;
            break;
        }
    }
    if(p==-1)
    {
        cout<<"yes\n"<<p+2<<" "<<q+1<<endl;
        return 0;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=v[i])
        {
            q=i;
            break;
        }
    }
    for(int i=0;i<=(q-p);i++)
    {
        if(v[p+i]!=a[q-i])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes\n"<<p+1<<" "<<q+1<<endl;
    return 0;
}
