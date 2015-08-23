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

struct Node{
    int val;
    Node lft, rgt;
};

struct TracsformNode{
    int treeSum;
    int greaterSum;
};

TracsformNode fun(Node root){
    if(root == null)
        return null;
    
    if(root.lft == null && root.rgt == null){
        TracsformNode t;
        t.treeSum = root.val;
        t.greaterSum = 0;
        return t;
    }
    
    TracsformNode lft =  fun(node.lft);
    TracsformNode rgt =  fun(node.rgt);
    
    TracsformNode result;
    result.treeSum = root.val;
    if(lft != null){
        result.treeSum += lft.treeSum;
    }
    
    if(rgt != null){
        result.treeSum += rgt.treeSum;
        result.greaterSum = rgt.treeSum;
        root.val = rgt.treeSum;
    }
    return result;
}

void transformTree(Node root){
    fun(root);
}

int main(){
    //create binary tree
    transformTree(root);
    return 0;
}