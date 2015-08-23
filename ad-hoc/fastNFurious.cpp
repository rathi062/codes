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
#define MX 10000007
#define MOD 1000000007

#define F first
#define S second
#define pii pair<int,int>
#define plli pair<LL,int>
#define p(i) printf("%d",i)
//#define inp(i) scanf("%d",&i)
//#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
inline void inp( int &n )
{
    n=0;
    int ch=getci();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getci();
    n=n*sign;
}

inline void inpll( long long &n )
{
    n=0;
    int ch=getci();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getci();
    n=n*sign;
}

using namespace std;

int main(){
    int  n;
    inp(n);
    int mx1 = 0, mx2 = 0, a, lst;
    inp(lst);
    for(int i=1;i<n;i++){
        inp(a);
        mx1 = max( abs(a-lst) , mx1);
        lst = a;
    }
    inp(lst);
    for(int i=1;i<n;i++){
        inp(a);
        mx2 = max( abs(a-lst) , mx2);
        lst = a;
    }
    if(mx1 == mx2)
    {
        cout<<"Tie\n"<<mx1<<endl;
    }
    else
    if(mx1 > mx2)
    {
        cout<<"Dom\n"<<mx1<<endl;
    }
    else{
        cout<<"Brian\n"<<mx2<<endl;
    }
    return 0;
    
}