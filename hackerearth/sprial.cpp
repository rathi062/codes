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

int n,m;
int a[10000][1000];
bool check[10000][1000];
int cnt,visited;

void printSprial(int i,int j,int direction){
    if(visited == cnt)
    return;
    if(check[i][j]){
        if(direction%4==0){
            printSprial(i+1,j-1,direction+1);
        }
        else
        if(direction%4==1){
            printSprial(i-1,j-1,direction+1);
        }
        else
        if(direction%4==2){
            printSprial(i-1,j+1,direction+1);
        }
        else
        if(direction%4==3){
            printSprial(i+1,j+1,direction+1);
        }
    }
    else
    {
        cout<<a[i][j]<<" ";
        visited++;
        check[i][j]=1;
        if(direction%4==0){
            printSprial(i,j+1,direction);
        }
        else
        if(direction%4==1){
            printSprial(i+1,j,direction);
        }
        else
        if(direction%4==2){
            printSprial(i,j-1,direction);
        }
        else
        if(direction%4==3){
            printSprial(i-1,j,direction);
        }
    }
}

int main(){
    inp(n);
    inp(m);
    cnt = n*m;
    visited = 0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    inp(a[i][j]);
    for(int i=0;i<=m+1;i++){
        check[0][i]=1;
        check[n+1][i]=1;
    }
    for(int i=0;i<=n+1;i++){
        check[i][0]=1;
        check[i][m+1]=1;
    }
    //    for(int i=0;i<=n+1;i++){
    //        for(int j=0;j<=m+1;j++)
    //        cout<<a[i][j]<<" ";
    //        cout<<endl;
    //    }
    
    printSprial(1,1,0);
}
