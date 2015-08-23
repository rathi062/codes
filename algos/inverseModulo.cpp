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
#define MX 1000006
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
/*inline void inpll( LL &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }*/


using namespace std;

LL powerWithMod(LL base, int pwr, LL mod){
    if(pwr==0)
        return 1;
    if(pwr==1)
        return base;
    LL result, ret;
    if(pwr%2){
        result = base;
        ret = powerWithMod(base, pwr/2, mod);
    }
    else{
        result = 1;
        ret = powerWithMod(base, pwr/2, mod);
    }
    result = result*ret;
    if(result >= mod) result = result % mod;
    result = result*ret;
    if(result >= mod) result = result % mod;
    return result;
}

LL inverseModulo(LL a, LL mod){
    return powerWithMod(a,mod-2,mod);
}

int main()
{
    LL a;
    cin>>a;
    //    cout<<powerWithMod(a, 1000, MOD)<<endl;
    LL result = inverseModulo(a,MOD);
    cout<<result;
    return 0;
}
