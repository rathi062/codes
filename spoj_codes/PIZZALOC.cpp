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
int k,m,n;
double r;
int locationX[21],locationY[21];
vector<int> service[21];
int solitaireX[101],solitaireY[101], people[101];

LL sqaure(int a){
    return a*a;
}

LL getDistance(int ax, int ay, int bx, int by){
    return sqaure(ax-bx) + sqaure(ay-by);
}

void calculateEachLocationsDeliverable(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(getDistance( locationX[i], locationY[i], solitaireX[j], solitaireY[j]) <= r){
                service[i].PB(j);
            }
        }
    }
}

int getBitsCountInNumber(int number, int bitsToCheck){
    int cnt = 0;
    for(int j=0;j<bitsToCheck;j++){
        if(number & (1<<j))
            cnt++;
    }
    return cnt;
}

bool isFeasible(int number){
    bool check[101] = {0};
    for(int i=0;i<m;i++){
        if(i & (1<<m)){
            for(int j=0;j<service[i].size();j++){
                if( check[ service[i][j] ])
                    return false;
                else
                    check[ service[i][j] ] = true;
            }
        }
    }
    return true;
}

int getCountOfServedPeople(int number){
    int ans = 0;
    bool check[101] = {0};
    for(int i=0;i<m;i++){
        if(number & (1<<i)){
            for(int j=0;j<service[i].size();j++){
                if(!check[ service[i][j] ]){
                    ans += people[ service[i][j] ];
                    check[ service[i][j] ] = true;
                }
            }
        }
    }
    return ans;
}

int getMaximumServedPeopleCount(){
    int ans = 0;
    for(int i=0;i<(1<<m);i++){
        int setBitsCount = getBitsCountInNumber(i,m);
        if(setBitsCount == k ){
            int cnt = getCountOfServedPeople(i);
            if(cnt > ans) ans = cnt;
        }
    }
    return ans;
}

int main(){
    cin>>k>>r>>m;
    r=r*r;
    for(int i=0;i<m;i++){
        cin>>locationX[i]>>locationY[i];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>solitaireX[i]>>solitaireY[i]>>people[i];
    }
    calculateEachLocationsDeliverable();
    cout<<getMaximumServedPeopleCount()<<endl;
    return 0;
}