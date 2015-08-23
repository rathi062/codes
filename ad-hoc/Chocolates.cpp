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

int arr[201][201], choco[201],bool check[201];
int mx;

LL GCD(LL a, LL b){
    if(b > a){
        LL tmp = b;
        b = a;
        a = tmp;
    }
    LL rem = b;
    while(a%b != 0){
        rem = a%b;
        a=b;
        b=rem;
    }
    return rem;
}

void printArray(int n){
    for(int i=1;i<=n; i++){
        for(int j=1;j<=n;j++)
            cout<<arr[i][j];
        cout<<endl;
    }
}

void changeToMinAssignment(int n){
    for(int i=1;i<=n; i++){
        for(int j=1;j<=n;j++)
            arr[i][j] = abs(arr[i][j]-mx);
    }
}

int getResult(int n){
    changeToMinAssignment(n);
    
}

int main(){
    int t;
    inp(t);
    while(t--){
        CLR(arr);
        CLR(choco);
        CLR(check);
        int n,k;
        inp(n);
        inp(k);
        for(int i=1;i<n;i++){
            inp(choco[i]);
        }
        int f,s;
        mx=0;
        for(int i=0;i<k;i++){
            inp(f);
            inp(s);
            arr[f][s] = GCD(f,s);
            arr[s][f] = arr[f][s];
            if(mx<arr[s][f])
                mx = arr[s][f];
        }
        
//        printArray(n);
        cout<<getResult(n);
    }
    
    return 0;
}