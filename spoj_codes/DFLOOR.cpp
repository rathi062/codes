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
#define MX 10000005
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

int r,c,num;
string s[20], newArr[20];

void flip(int i,int j){
    if(s[i][j]=='1') s[i][j] = '0';
    else s[i][j] = '1';
}

void changeBit(int i,int j){
    if(i>0) flip(i-1,j);
    if(i<r-1) flip(i+1,j);
    if(j>0) flip(i,j-1);
    if(j<c-1) flip(i,j+1);
    flip(i,j);
}

void flipArr(int i,int j){
    if(newArr[i][j]=='1') newArr[i][j] = '0';
    else newArr[i][j] = '1';
}

void changeArrBit(int i,int j){
    if(i>0) flipArr(i-1,j);
    if(i<r-1) flipArr(i+1,j);
    if(j>0) flipArr(i,j-1);
    if(j<c-1) flipArr(i,j+1);
    flipArr(i,j);
}

int isBoardClear(){
    for(int i=0;i<c;i++){
        if(newArr[r-1][i]=='0')
            return MX;
    }
    return 0;
}

stack<pii> finalStk, stk;
bool ans = false;

void emptyStacks(){
    while(!stk.empty()){
        stk.pop();
    }
    while(!finalStk.empty()){
        finalStk.pop();
    }
}


void printStacks(){
    cout<<stk.size()+finalStk.size()<<endl;
    while(!stk.empty()){
        pii p = stk.top();
        stk.pop();
        cout<<p.second+1<<" "<<p.first+1<<endl;
    }
    while(!finalStk.empty()){
        pii p = finalStk.top();
        finalStk.pop();
        cout<<p.second+1<<" "<<p.first+1<<endl;
    }
}

int getCount(int i,int j){
    
    if(ans) return -1;
    if(j==c) return getCount(i+1,0);
    if(i==0){
        int rs1 = getCount(i,j+1);
        if(ans){
            return -1;
        }
        stk.push(MP(i,j));
        changeBit(i,j);
        int rs2 = getCount(i,j+1) + 1;
        if(ans){
            return -1;
        }
        stk.pop();
        changeBit(i,j);
        return min(rs1,rs2);
    }
    else{
        //        cout<<"string number #"<<++num<<": "<<s[0]<<endl;
        stack<pii> localStk;
        for(int x=0;x<r;x++) newArr[x] = s[x];
        for(int x=i;x<r;x++){
            for(int y=0;y<c;y++){
                if(newArr[x-1][y]=='0'){
                    localStk.push(MP(x,y));
                    changeArrBit(x,y);
                }
            }
        }
        if(!isBoardClear()){
            finalStk = localStk;
            printStacks();
            ans=true;
            return -1;
        }
            
        return isBoardClear();
    }
}

int main(){
    inp(c);
    inp(r);
    while(r!=0 || c!=0){
        emptyStacks();
        ans = false;
        for(int i=0;i<r;i++){
            cin>>s[i];
        }
        num = 0;
        int cnt = getCount(0,0);
        if(cnt != -1)
            cout<<"-1\n";
        inp(c);
        inp(r);
    }
}
