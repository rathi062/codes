//
//  STFM.cpp
//  
//
//  Created by mohit rathi on 11/02/15.
//
//
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
#define MX 100003
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

long long power(long long n,long long p, long long m){
    if(p==1)
        return (n%m);
    if(p%2){
        long long result = power(n,p>>1,m);
        result = (result*result)%m;
        result = (result*n)%m;
        return result;
    } else {
        long long result = power(n,p>>1,m);
        result = (result*result)%m;
        return result;
    }
        
}
long long factorial(long long n,long long m){
    if(m==1) return 0;
    if(n==1) return 1;
    long long result = factorial(n%m,m) * power( factorial(m-1,m) , (n/m), m ) *
                        factorial(n/m , m) * power(m , n/m, m);
    result = result%m;
    if(result<0)
        result+=m;
    return result;
}

long long fun(long long n,long long m){
    long long result = factorial(n+1,m);
    result--;
    if(result<0)
        result+=m;
    return result;
}
int main()
{
    long long n,m,no,result=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>no;
        result+=fun(no,m);
    }
    return 0;
}
