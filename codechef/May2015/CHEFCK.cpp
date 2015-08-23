#include<iostream>
#include <stdlib.h>
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
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 10000007
#define MOD 1000000007

#define F first
#define S second
#define pii pair<int,int>
#define plli pair<LL,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
//#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

inline void inpll( long long &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}

 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }

using namespace std;

LL min(LL a, LL b){
    if(a<b) return a;
    else return b;
}


LL A[MX];

int N, K, Q;
LL a, b, c, d, e, f, r, s, t, m, fst;
LL L1, La, Lc, Lm, D1, Da, Dc, Dm;

LL powerWithMod(LL base, int pwr, LL mod){
    if(pwr==0)
        return 1;
    if(pwr==1)
        return base;
    LL result, ret;
    if(pwr%2){
        result = base;
    }
    else{
        result = 1;
    }
    ret = powerWithMod(base, pwr/2,mod);
    result = result*ret;
    if(result >= mod) result = result % mod;
    result = result*ret;
    if(result >= mod) result = result % mod;
    return result;
}

LL kMinArray[MX];
int indexes[MX];

int pos;

int getPosition(int i,int j, long long remaining){
    
    if(i==j)
        return i;
    int mid = (i+j)/2;
    if(A[mid]>remaining)
        return getPosition(i,mid,remaining);
    else
        return getPosition(mid+1,j,remaining);
    
}

int getMinValue(int i,int j, int idx){
    if(i==j)
        return indexes[i];
    int mid = (i+j)/2;
    if(indexes[mid]==idx)
        return mid;
    if(indexes[mid]>idx)
        return getMinValue(i,mid,idx);
    else
        return getMinValue(mid+1,j,idx);
}

void createKMinArray(LL val, int idx){
    if(A[pos] <= val){
        A[++pos] = val;
        indexes[pos] = idx;
    }
    else{
        pos = getPosition(max(1,pos-K+1),pos,val);
        A[pos] = val;
        indexes[pos] = idx;
    }
    if(idx >=K){
        kMinArray[idx] = A[ getMinValue(max(1,pos-K+1),pos,idx-K+1) ];
    }
}

LL getQueryResult(LL L,LL R){
    return min( kMinArray[L+K-1], kMinArray[R]);
}

void createArray(){
    A[0]=0;
    pos = 1;
    indexes[1]=1;
//    createKMinArray(A[1],1);
    LL pwr = t;
    for( int x = 2;x<=N;x++){
        pwr *= t;
        if(pwr > s) pwr %= s;
        if(pwr  <= r)        // Here t^x signifies "t to the power of x"
            A[x] = ((a*powerWithMod(A[x-1],2,m))%m+ (b*A[x-1])%m + c) % m;
        else
            A[x] = ((d*powerWithMod(A[x-1],2,m))%m + (e*A[x-1])%m + f) % m;
        if(N>1000)
        createKMinArray(A[x],x);
    }
}

LL bruteForce(int L, int R){
    LL mn = A[L];
    for(int i=L;i<=R;i++)
        if(mn > A[i])
            mn = A[i];
    return mn;
}

void createQuery(){
    LL sum=0,product=1;
    for (int i=1; i<=Q; i++){
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        LL L = L1 + 1;
        LL R = min(L + K - 1 + D1, N);
        LL queryResult;
        if(N > 1000)
            queryResult = getQueryResult(L,R);
        else
            queryResult = bruteForce(L,R);
        sum += queryResult;
        product *= queryResult;
        if(product > MOD)
            product %= MOD;
    }
    if(product < 0) product += MOD;
    cout<<sum<<" "<<product<<endl;
}

void printArray(){
    for(int i=1;i<=N;i++)
        cout<<A[i]<<" ";
}

int main(){
    
    inp(N);
    inp(K);
    inp(Q);
    
    inpll(a);
    inpll(b);
    inpll(c);
    inpll(d);
    inpll(e);
    inpll(f);
    inpll(r);
    inpll(s);
    inpll(t);
    inpll(m);
    inpll(fst);
    
    inpll(L1);
    inpll(La);
    inpll(Lc);
    inpll(Lm);
    inpll(D1);
    inpll(Da);
    inpll(Dc);
    inpll(Dm);
    
    A[1] = fst;
    createArray();
    createQuery();
    return 0;
}