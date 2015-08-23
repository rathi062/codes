
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
#define MX 100005
#define MOD 1000000007

#define pipii pair<int, pair<int,int> >
#define F first
#define S second

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
struct Node{
    int val, scndVal;
    vector<int> primeFactors;
}a[MX];
int n,k;

bool c[MX];
vector<LL> v;
void seive()
{
    c[0]=1;
    c[1]=1;
    //printf("%lld\n",l);
    for(int i=2;i<MX;i+=2)
        c[i]=1;
    for(int i=3;i<3164;i+=2)
        for(int j=i*i,d=i<<1;j<MX;j+=d)
            c[j]=1;
    v.push_back(2);
    for(int i=3;i<MX;i+=2)
        if(!c[i])
            v.push_back(i);
}

vector<int> getPrimeFactors(int val){
    vector<int> result;
    if(val < 0)
        return result;
    int idx = 0;
    while(val >= 1 && val >= v[idx]){
        if(!c[val]){
            result.PB(val);
            return result;
        }
        if(! (val%v[idx]) ){
            result.PB(v[idx]);
            val /= v[idx];
        }
        else{
            idx++;
        }
    }
    return result;
}

struct Tree{
    int val;
    int lstIdx;
    map<int, Tree*> children;
}*root;


void insertIntoTree(int idx){
    vector<int> path = a[idx].primeFactors;
    Tree* ptr = root;
    if(a[idx].scndVal == 0){
        ptr->lstIdx = idx;
        return;
    }
    for(int i=0;i<path.size();i++){
        if(ptr->children.find(path[i]) == ptr->children.end()){
            Tree * newNode = new Tree();
            newNode->lstIdx = idx;
            newNode->val = path[i];
            ptr->children[path[i]] = newNode;
            ptr = ptr->children[path[i]];
        }
        else{
            ptr->children[path[i]]->lstIdx = idx;
            ptr = ptr->children[path[i]];
        }
    }
}

int checkForLstSimilarValue(vector<int> path){
    int result = -1;
    Tree* ptr = root;
    for(int i=0;i<path.size();i++){
        if(ptr->children.find(path[i]) == ptr->children.end()){
            return -1;
        }
        else{
            ptr = ptr->children[path[i]];
        }
    }
    result = ptr->lstIdx;
    return result;
}

int  main(){
    seive();
    LL sum = 0;
    int mxIdx = -1;
    inp(n);
    inp(k);
    Tree * ptr = new Tree();
    ptr->lstIdx = -1;
    ptr->val = 0;
    root = ptr;
    for(int i=0;i<n;i++){
        inp(a[i].val);
        a[i].scndVal = a[i].val - k;
        a[i].primeFactors = getPrimeFactors(a[i].scndVal);
        int result = checkForLstSimilarValue(getPrimeFactors(a[i].val));
        if(result != -1){
            if(result > mxIdx)
                mxIdx = result;
        }
        sum += i-mxIdx;
        insertIntoTree(i);
    }
    cout<<sum<<endl;
    return 0;
}