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
double pwr(double no, int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return no;
    double ans = 1;
    if(n%2)
        ans*=no;
    double hlf = pwr(no,n/2);
    return ans*hlf*hlf;
}
double maxExpectation(int n,int m)
{
    double minus=0.0,sum=n;
    for(double i=1;i<=n;i++)
    {
        minus+=pwr(double(i/n),m);
    }
    return (sum-minus+1);
}

double normalExpectation(int n,int m)
{
    double a[MX],sum;
    CLR(a);
    a[0]=0.0;
    for(int i=1;i<=m;i++)
    {
        if(i<=n)
        {
            sum=0.0;
            for(int j=1;j<i;j++)
            {
                sum+=a[j];
            }
            for(int j=i;j<=n;j++)
            {
                sum+=j;
            }
            a[i]=sum/n;
        }
        else
        {
            sum=0.0;
            for(int j=1;j<=n;j++)
                sum+=a[i-j];
            a[i]=sum/n;
        }
    }
    return a[m];
}
int main()
{
    int t=0;
    int n,m;
    inp(n);
    inp(m);
    printf("normal expactaion : %.10lf\n",normalExpectation(n,m));
    printf("maxExpactation  : %.10lf\n",maxExpectation(n,m));
    
    return 0;
}
