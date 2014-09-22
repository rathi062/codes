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

int a[MX];
using namespace std;
int main()
{
    int t=0;
    int n;
    inp(n);
    for(int i=0;i<n;i++)
        inp(a[i]);
    int min1 = a[0];
    int max1,i,b=0,in;
    for(i =0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
            continue;
        else
        {
            b=1;
            break;
        }
    }
    if(b==0)
    {
        cout<<"0";
        return 0;
    }
    if(b==1)
    {
        in=i;
        i++;
        max1=a[i];
        b=0;
        for(i;i<n-1;i++)
        {
            if(a[i]<=a[i+1])
            {
                max1=a[i+1];
                continue;
            }
            else
            {
                b=1;
                break;
            }
        }
    }
    if(b==1 || min1<max1)
    {
        cout<<"-1";
        return  0;
    }
    cout<<(n-in-1);
    return 0;
}
