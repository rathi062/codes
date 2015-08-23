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
#define MX 100000000000014

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
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

using namespace std;
int  arr[MX],y;
LL res=MX;
LL reverse(LL n){
    LL result = 0;
    LL md = 10,lst;
    while(n){
        lst = n%10;
        result = result*md + lst;
        n = n/10;
    }
    return result;
}

void fun(LL n,LL val){
    if(n==y){
        res = min(val,res);
        return;
    }
    if(n>(MX-3) && n>y)
        return;
    if(res<=val)
        return;
    LL nxt1 = n+1;
    LL nxt2= reverse(n);
    if(nxt2>n && nxt2<MX)
        fun(nxt2,val+1);
    fun(nxt1,val+1);
}
int main(){
    int t;
    cin>>t;
    fun(1,1);
    for(int i=0;i<t;i++){
        cin>>y;
        res = MX;
        cout<<"Case #"<<i+1<<": ";
        cout<<arr[y]<<endl;
    }
    return 0;
}