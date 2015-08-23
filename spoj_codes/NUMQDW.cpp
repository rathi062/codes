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
#define cls(a) memset(a,-1,sizeof(a))
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
#define MOD 1000000007
#define pii pair<int,int>
#define psi pair<string ,int>

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
int t,n,c,sz;
string s;
vector<char> v[6];
bool done[6];

void init(){
    for(int i=0;i<c;i++) for(int j=0;j<c;j++) v[i].PB(char(65+j));
}

void correctV(){
    int cnt=0;
    for(int i=0;i<sz;i++){
        int idx = int(s[i])-65;
        if(!done[idx]){
            for(int j=i+1;j<sz;j++){
                vector<char>::iterator it;
                it = find(v[idx].begin(), v[idx].end(), s[j]);
                if( it != v[idx].end()){
                    v[idx].erase(it);
                }
            }
            done[idx]=1;
            cnt++;
        }
        if(cnt==c)
            break;
    }
}
int main(){
    inp(t);
    while(t--){
        CLR(done);
        CLR(v);
        inp(n);
        inp(c);
        cin>>s;
        sz = s.size();
        init();
        correctV();
        
    }
}
