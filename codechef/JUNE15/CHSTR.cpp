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
#define MX 5005
#define MOD 1000000009
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
int m,n,k;
string s;
LL nCr[MX][MX];
LL frequencyCount[MX];
LL dp[MX];
bool check[MX];

struct sufixTreeNode{
    char c;
    int val;
    sufixTreeNode *nxts[26];
} *root;

int getIdx(char c){
    return c-97;
}

sufixTreeNode * createSufixTreeNode(char c){
    sufixTreeNode* node = new sufixTreeNode;
    node->c = c;
    node->val = 0;
    for(int i=0;i<26;i++)
        node->nxts[i]=NULL;
    return node;
}

void putInRoot(string s){
    int l= s.size();
    sufixTreeNode *crntNode = root;
    for(int i=0;i<l;i++){
        char c = s[i];
        int idx = getIdx(c);
        if(crntNode->nxts[idx] == NULL){
            crntNode->nxts[idx] = createSufixTreeNode(c);
        }
        crntNode = crntNode->nxts[idx];
        if(crntNode->val > 0)
            frequencyCount[crntNode->val] --;
        crntNode->val++;
        frequencyCount[crntNode->val] ++;
    }
}

void sufixTree(string s){
    int l= s.size();
    root = createSufixTreeNode('.');
    for(int i=0;i<l;i++){
        putInRoot(s.substr(i,l));
    }
}


void init(){
    for(int i=0;i<MX;i++)
    nCr[i][0] = 1;
    for(int i=1;i<MX;i++)
        nCr[0][i] = 0;
    for(int i=1;i<MX;i++){
        for(int j=1;j<=i;j++){
            nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            if(nCr[i][j] >= MOD)
            nCr[i][j] %= MOD;
            while(nCr[i][j] < 0)
                nCr[i][j] += MOD;
        }
    }
}

LL geTnCr(int n, int r){
    r = (n-r) < r ? (n-r) : r;
    return nCr[n][r];
}

void process(){
    CLR(frequencyCount);
    CLR(dp);
    CLR(check);
    sufixTree(s);
}

LL Solve(int k){
    if(check[k])
        return dp[k];
    LL result = 0;
    for(int i=k;i<=n;i++){
        
        LL toAdd = frequencyCount[i] * geTnCr(i, k);
        if(toAdd >=MOD)
            toAdd %= MOD;
        while(toAdd < 0)
            toAdd += MOD;
        
        result += toAdd;
        if (result >= MOD) {
            result %= MOD;
        }
        while(result < 0)
            result += MOD;
    }
    check[k] = 1;
    dp[k] = result;
    return result;
}

int main(){
    int t;
    inp(t);
    init();
    while(t--){
        inp(n);
        inp(m);
        cin>>s;
        n = s.size();
        process();
        for(int i=0;i<m;i++){
            inp(k);
            if(k>n)
                cout<<"0"<<endl;
            else
                cout<<Solve(k)<<endl;
        }
    }
}
