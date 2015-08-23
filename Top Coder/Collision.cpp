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

#define PB push_back
#define LL long long
#define pii pair<int, int>
#define MP(a,b) make_pair(a,b)
#define CLR(a) memset(a,0,sizeof(a))
#define MX 100001

//#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
inline void inp( int &n )
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

double getProb1(int a,int b,int total){
    double ans = 1.0;
    int free = total;
    for(int i=1;i<(a+b);i++){
        ans *= ((free - i)*1.0/total);
    }
    return ans;
}

double getProb2(int a,int b,int total){
    double ans = 1.0;
    int free = total;
    for(int i=0;i<a;i++){
        ans *= ((free - i)*1.0/(total-i));
    }
    free -= a;
    for(int i=0;i<b;i++){
        ans *= ((free - i)*1.0/(total-i));
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,total;
        cin>>a>>b>>total;
        double prob1,prob2;
        prob1 = prob2 = 1.0;
        prob1 = getProb1(a,b,total);
        prob2 = getProb2(a,b,total);
        cout<<endl<<prob1<<" "<<prob2<<endl;
    }
}