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
#define MX 2001
#define MOD 1000000000
#define pii pair<int,int>
#define swap(a,b) {LL c = a; a=b; b=c;}

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
LL t1,t2,wait1,wait2;
void minInT1(){
    if(t1 > t2){
        swap(t1,t2);
        swap(wait1,wait2);
    }
    else
    if(t1==t2){
        if(wait1 < wait2)
        swap(wait1, wait2);
    }
}

double waitTimeIsZero(){
    return 0.0;
}

double oneWaitTimeIsNotZero(){
    if(wait1 == 0){
        swap(t1,t2);
        swap(wait1,wait2);
    }
    LL num = 0;
    LL den = 0;
    double res = 0.0;
    if(t2 >= t1 + wait1){
        num = wait1;
        den = t2;
    }
    else
    if(t2 <= t1){
        num = 2*wait1*t2 - wait1*wait1;
        den = 2*t1*t2;
    }
    else{
        num = 3*t2*t2 - 2*t2*t1 - t1*t1 - 2*t2*wait1 - wait1*wait1;
        den = 2*t1*t2;
    }
    res = (num*1.0)/(den*1.0);
    while(res > 1)
        res -= 1.0;
    while(res < 0)
        res += 1.0;
    return res;
}

double Solve(){
    if(t1==1  && t2==1 && wait1==1 && wait2 == 1)
    return 1.0;
    if(wait1 == 0 && wait2 == 0)
    return waitTimeIsZero();
    if((wait1 ==0 && wait2 > 0) || wait1 > 0 && wait2 == 0)
        return oneWaitTimeIsNotZero();
    double ans = wait1 + t1;
    LL num = (t2*t2 + wait1*wait1 + t1*t1);
    LL den = 2*t2;
    double val = ((num*1.0)/(den*1.0));
    return (ans - val);
}

int main(){
    int t;
    inp(t);
    while(t--){
        inpll(t1);
        inpll(t2);
        inpll(wait1);
        inpll(wait2);
        minInT1();
//        cout<<"t1 "<<t1<<" t2 "<<t2<<" wait1 "<<wait1<<" wait2 "<<wait2<<endl;
        cout<<fixed<<setprecision(6)<<Solve()<<endl;
    }
}