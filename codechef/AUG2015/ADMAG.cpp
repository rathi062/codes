
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
#define MX 91
#define MOD 1000000007

#define pipii pair<int, pair<int,int> >
#define F first
#define S second

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

using namespace std;
LL fibo[MX];
void init(){
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i=3;i<MX;i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
}

int search(int a, int b, LL n){
    for(int i=1;i<MX;i++)
        if(fibo[i] > n)
            return i-1;
    return 0;
//    if(a>=b || fibo[a] >= n)
//        return a;
//    int mid = (a+b)/2;
//    if(fibo[mid] == n)
//        return mid;
//    if(fibo[mid] < n)
//        return search(mid,b,n);
//    else
//        return search(a,mid-1,n);
}

int  main(){
    int t;
    init();
    inp(t);
    while(t--){
        LL n;
        inpll(n);
        cout<<search(1,MX,n)<<endl;
    }
    return 0;
}