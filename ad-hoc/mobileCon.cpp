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
#define MX 100005

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



struct Node{
    int x,t,p;
}node[MX];

int comp(const Node a,const Node b)
{
    if(a.p >=0 && b.p >= 0){
        return ((a.t==b.t)?(a.p>b.p):(a.t<b.t));
    }
    if(a.p < 0 && b.p < 0)
        return ((a.t==b.t)?(a.p>b.p):(a.t>b.t));
    
    if(a.p >= 0 && b.p < 0)
        return 1;
    
    if(a.p < 0 && b.p >= 0)
        return 0;
    
    return 1;
}


int main(){
    int n;
    inp(n);
    for(int i=0;i<n;i++){
        cin>>node[i].t>>node[i].x;
        node[i].p = node[i].x-node[i].t;
    }
    sort(node,node+n,comp);
//    for(int i=0;i<n;i++){
//        cout<<node[i].t<<" "<<node[i].x<<endl;
//    }
    int current = node[0].t, min = node[0].t;
    for(int i=0;i<n;i++){
        if(current<node[i].t){
            min += node[i].t - current;
            current = node[i].t;
        }
        current -= node[i].t;
        current += node[i].x;
    }
    cout<<min<<endl;
    return 0;
}