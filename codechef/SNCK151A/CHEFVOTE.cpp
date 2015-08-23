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

struct Node{
    int idx;
    int cnt;
    int votedTo;
} a[51];

int n,crnt;

int cntBasedCompare(const Node a, const Node b){
    return (a.cnt==b.cnt) ? (a.idx<b.idx) : (a.cnt>b.cnt);
}

int idxBasedCompare(const Node a, const Node b){
    return (a.idx<b.idx);
}

int getNextVotingIndex(int idx){
    if(idx < n-1){
        if(a[idx+1].cnt > 0){
            a[idx+1].cnt--;
            return a[idx+1].idx;
        }
    }
    while(1){
        if(crnt > n)
            crnt = 0;
        if(a[crnt].cnt > 0){
            a[crnt].cnt--;
            return a[crnt].idx;
        }
        crnt++;
    }
}

void assignVotes(){
    for(int i=0;i<n;i++){
        int idx = getNextVotingIndex(i);
        a[i].votedTo = idx;
    }
}

int main(){
    int t;
    inp(t);
    while(t--){
        inp(n);
        int sum = 0;
        bool possible = true;
        for(int i=0;i<n;i++){
            a[i].idx = i;
            inp(a[i].cnt);
            sum += a[i].cnt;
            if(a[i].cnt == n)
                possible = false;
        }
        if(sum != n)
            possible = false;
        if(!possible)
        {
            cout<<"-1\n";
            continue;
        }
        sort(a,a+n,cntBasedCompare);
        crnt = 0;
        assignVotes();
        sort(a,a+n,idxBasedCompare);
        for(int i=0;i<n;i++){
            cout<<a[i].votedTo+1<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}