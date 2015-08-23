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
//#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
inline void inp( int &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }
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

LL fctorl[100005], nume[100005], deno[100005];

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

LL nCr(LL n, LL r){
    r = r < (n-r) ? r : (n-r);
    LL num=1,den=1;
    num = nume[n-r+1]*inverseModulo(nume[n+1], MOD);
    if(num >= MOD)
        num %= MOD;
    
    den = deno[r];
    LL inverseDen = inverseModulo(den, MOD);
    LL result = inverseDen * num;
    if(result >= MOD)
        result %= MOD;
    return result;
}

void numeratorDenominator(){
    nume[0] = 1;
    deno[0] = 1;
    LL num=1, n =100005 ,den=1, result = 1;
    for(LL i=n-1,j=1;i>0;i--,j++){
        num *= i;
        if(num >= MOD)
            num %= MOD;
        nume[i] = num;
        
        den *= j;
        if(den >= MOD)
            den %= MOD;
        deno[j] = den;
        
        result *= j;
        if(result >= MOD)
            result %= MOD;
        fctorl[j] = result;
    }
}

void preCompute(){
    numeratorDenominator();
}

int main()
{
    preCompute();
    int n;
    inp(n);
    int a[n];
    LL sum=0;
    int val;
    int frequency[100005];
    LL fact[100005];
    bool check[100005];
    vector<int> differentCosts;
    for(int i=0;i<n;i++){
        CLR(frequency);
        CLR(check);
        inp(a[i]);
        sum += a[i];
        for(int j=0;j<a[i];j++){
            inp(val);
            if(check[val]){
                frequency[val]++;
            }
            else{
                check[val] = 1;
                differentCosts.PB(val);
                frequency[val] = 1;
            }
        }
        
        LL prduct = 1;
        while(!differentCosts.empty()){
            val = differentCosts.back();
            differentCosts.pop_back();
            int frq = frequency[val];
            LL facto = fctorl[frq];
            prduct *= facto;
            if(prduct >= MOD)
                prduct %= MOD;
        }
        fact[i] = prduct;
    }
    LL remaining = sum;
    LL result = 1;
    for(int i=0;i<n;i++){
        result *= nCr(remaining,a[i]);
        if(result >=MOD)
            result %= MOD;
        result *= fact[i];
        if(result >=MOD)
            result %= MOD;
        remaining -= a[i];
    }
    cout<<result<<endl;
    return 0;
}
