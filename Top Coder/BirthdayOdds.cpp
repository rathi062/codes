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

int main(){
    int minOdds,days;
    inp(minOdds);
    inp(days);
    double p = 1.0;
    int num = 1;
    double final = 1 - double(minOdds*1.0/100);
    while(p > final){
        p = p*(1-(num*1.0/days));
        num++;
    }
    cout<<num<<endl;
}