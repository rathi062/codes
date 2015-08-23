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
#define Mi 1000000005

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
int main(){
    int t;
    inp(t);
    for(int i=0;i<t;i++){
        int d,no,ans;
        priority_queue<int> q;
        inp(d);
        for(int j=0;j<d;j++){
            inp(no);
            q.push(no);
        }
        ans = q.top();
        int cnt=0;
        no = q.top();
        while(q.top()>1){
            cnt++;
            q.pop();
            if(no%2){
                q.push(no/2);
                q.push((no+1)/2);
            }
            else{
                q.push(no/2);
                q.push(no/2);
            }
            no = q.top();
            ans = min(ans, no + cnt);
        }
        cout<<"Case #"<<i+1<<": "<<ans;
        if(i!=t-1)
            cout<<endl;
    }
}