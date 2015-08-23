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
#define MX 5001
#define MOD 1000000009
#define pii pair<int,int>
#define pdi pair<double,int>
#define plli pair<LL,int>
#define pll pair<LL,LL>

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

LL area(pll p1, pll p2){
    LL v1 = p1.first*p2.second;
    LL v2 = p1.second*p2.first;
    LL res = v1 - v2;
    return res;
}

LL areaOfPolygon(vector<pll> points){
    LL sum = 0;
    int l = points.size();
    for(int i=0;i<l;i++){
        sum += area(points[i], i==l-1 ? points[0]:points[i+1]);
    }
    if(sum < 0)
        sum *= -1;
    return sum;
}

int main(){
    int t,n,p;
    LL x,y;
    inp(t);
    while(t--){
        inp(n);
        vector<plli> polygonArea;
        int outputArr[n];
        for(int j=0;j<n;j++){
            inp(p);
            vector<pll> points;
            for(int i=0;i<p;i++){
                inpll(x);
                inpll(y);
                points.PB(MP(x,y));
            }
            polygonArea.PB(MP(areaOfPolygon(points), j));
        }
        sort(polygonArea.begin(), polygonArea.end());
        for(int i=0;i<n;i++){
            outputArr[polygonArea[i].second] = i;
        }
        for(int i=0;i<n;i++){
            cout<<outputArr[i]<<" ";
        }
        cout<<endl;
    }
}
