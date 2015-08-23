
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
LL n,h,a,b;
LL cleared[MX], req[MX];
int  main(){
    int t;
    inp(t);
    while(t--){
        CLR(cleared);
        CLR(req);
        inpll(n);
        inpll(h);
        for(int i=0;i<n;i++){
            inpll(a);
            inpll(b);
            cleared[a]++;
            cleared[b+1]--;
        }
        LL toAdd = 0;
        for(int i=0;i<n;i++){
            toAdd += cleared[i];
            req[i] = n - toAdd;
        }
        LL ans = h*n, sum=0;
        FOR(i,n){
            if(i<h){
                sum += req[i];
            }
            else{
                if(ans > sum)
                    ans = sum;
                sum -= req[i-h];
                sum += req[i];
            }
        }
        if(ans > sum)
            ans = sum;
        cout<<ans<<endl;
    }
    return 0;
}