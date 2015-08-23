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
#define MX 10000009
#define pii pair<int,int>
#define pil pair<int,long>

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
int n,arr[16],allSet;
pil dp[101][1<<16];
bool check[101][1<<16];

int getPerimeter(int lstHight, int crntHight, int usedSet){
    int result = 2 + abs(lstHight - crntHight);
    if(usedSet == allSet) result += crntHight;
    return result;
}

pil histogram(int lstHight, int usedSet){
    if(check[lstHight][usedSet])
        return dp[lstHight][usedSet];
    if(usedSet == allSet)
        return MP(0,1);
    int val=0;
    pil result = MP(0,0);
    for(int i=0;i<n;i++){
        if( !(usedSet & (1<<i)) ){
            int nwUsedSet = usedSet | (1<<i);
            val = getPerimeter(lstHight, arr[i], nwUsedSet);
            pil ret = histogram(arr[i], nwUsedSet);
            if(ret.first + val > result.first){
                result.first = ret.first + val;
                result.second = ret.second;
            }
            else
                if(ret.first + val == result.first)
                    result.second += ret.second;
        }
    }
    check[lstHight][usedSet] = 1;
    dp[lstHight][usedSet] = result;
    return result;
}

//pii histogram(int lstHight, int usedSet, int peri){
//    if(check[lstHight][usedSet])
//        return dp[lstHight][usedSet];
//    if(usedSet == allSet) return MP(peri,1);
//    int val=0,res;
//    pii result = MP(0,0);
//    for(int i=0;i<n;i++){
//        if( !(usedSet & (1<<i)) ){
//            int nwUsedSet = usedSet | (1<<i);
//            val = getPerimeter(lstHight, arr[i], nwUsedSet);
//            res = peri + val;
//            pii ret = histogram(arr[i], nwUsedSet, res);
//            if(ret.first > result.first){
//                result.first = ret.first;
//                result.second = ret.second;
//            }
//            else
//            if(ret.first == result.first)
//                result.second += ret.second;
//        }
//    }
//    check[lstHight][usedSet] = 1;
//    dp[lstHight][usedSet] = result;
//    return result;
//}

int main(){
    inp(n);
    while(n){
        CLR(check);
        allSet = 0;
        for(int i=0;i<n;i++){
            inp(arr[i]);
            allSet |= (1<<i);
        }
        pil result = histogram(0,0);
        cout<<result.first<<" "<<result.second<<endl;
        inp(n);
    }
}
