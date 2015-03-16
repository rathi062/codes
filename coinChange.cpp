//
//  CHEFCH.cpp
//
//
//  Created by mohit rathi on 10/02/15.
//
//
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
#define MX 10
#define MOD 100000000

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
int dp[MX][MX];
int coins[MX];
int numberOfCoins;
stack<int> result;
void getKthSequence(int k,int n,int m){
    if(n<1) return;
    if(k==1){
        result.push(1);
        getKthSequence(1,n-1,m);
        return;
    }
    int sum=0;
    for(int i=0;i<m;i++){
        if(dp[n][i] < k)
            continue;
            
        if(dp[n-coins[i]][i-1] >= k-dp[n][i-1]){
            result.push(coins[i]);
            getKthSequence(k-dp[n][i-1],n-coins[i],i-1);
            return;
        }
        sum =
    }
}

void fun(){
    for(int i=0;i<MX;i++)
        dp[0][i]=1;

    for(int i=1;i<MX;i++){
        for(int j=0;j<numberOfCoins;j++){
            int x = (coins[j] <= i) ? dp[i-coins[j]][j]:0;
            int y = (j > 0) ? dp[i][j-1]:0;
            dp[i][j] = x + y;
        }
    }
    for(int i=0;i<numberOfCoins;i++){
        for(int j=1;j<MX;j++){
            cout<<dp[j][i]<<" ";
        }
        cout<<endl;
    }
}


void printResult(){
    while(!result.empty()){
        cout<<result.top()<<endl;
        result.pop();
    }
}
int main()
{

    cin>>numberOfCoins;
    CLR(coins);
    for(int i=0;i<numberOfCoins;i++)
        cin>>coins[i];
    CLR(dp);
    fun();
    int n;
    cin>>n;
    while(1){
        int k;
        cin>>k;
        getKthSequence(k,n,numberOfCoins);
        printResult();
    }
    return 0;
}
