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
#define MX 1000007
#define MOD 1000000007

#define F first
#define S second
#define pii pair<int,int>
#define pill pair<int,LL>
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
struct nodes{
    LL val;
    int idx;
} node[2*MX];

int a[MX];
int n,m;
nodes max(nodes a, nodes b){
    if(a.val>b.val) return a;
    else return b;
}

vector<pill> frequency;
LL cumulativeSum[MX];
//map<int, LL> frqMap;

int floorBinarySearch(int i, int j, int val){
    if(i==j)
        return i;
    if(i>j)
        return j;
    if(i+1==j){
        if(frequency[i].F < val && frequency[j].F >= val)
            return i;
        if(frequency[j].F < val)
            return j;
    }
    int mid = (i+j)>>1;
    if(frequency[mid].F < val)
        return floorBinarySearch(mid, j, val);
    else
        return floorBinarySearch(i, mid-1, val);
}

int ceilingBinarySearch(int i, int j, int val){
    if(i==j)
        return i;
    if(i > j)
        return j;
    int mid = (i+j)>>1;
    if(frequency[mid].F <= val)
        return ceilingBinarySearch(mid+1, j, val);
    else
        return ceilingBinarySearch(i, mid, val);
}

int equalBinarySearch(int i, int j, int val){
    if(i==j){
        if(frequency[i].F == val) return i;
        else return -1;
    }
    if(i>j) return -1;
    int mid = (i+j)>>1;
    if(frequency[mid].F == val)
        return mid;
    if(frequency[mid].F < val)
        return equalBinarySearch(mid+1, j, val);
    else
        return equalBinarySearch(i, mid-1, val);
}

void init(int idx, int st, int ed, int s, int e, LL val){
    if(st==s && ed==e){
        node[idx].val = val;
        node[idx].idx = s;
        return;
    }
    
    int lft = idx<<1, rgt = lft+1, mid = (st+ed)>>1;
    if(e<=mid) init(lft,st,mid,s,e,val);
    else init(rgt,mid+1,ed,s,e,val);
    
    node[idx] = max(node[lft], node[rgt]);
    return;
}

nodes query(int idx, int st, int ed, int s, int e){
    if(st==s && ed==e)
        return node[idx];
    
    int lft = idx<<1, rgt = lft+1, mid = (st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e);
    else
    {
        nodes l, r;
        l = query(lft, st, mid, s, mid);
        r = query(rgt, mid+1, ed, mid+1, e);
        return max(l,r);
    }
}

//void insertIntoMap(int key, LL val){
//    map<int,LL>::const_iterator got = frqMap.find (key);
//    if ( got == frqMap.end() )
//        frqMap.insert(MP(key,val));
//    else
//        frqMap[key] = frqMap[key] + val;
//}

void createFrequencyArray(int i,int j){
    if(i>j)
        return;
    if(i==j){
//        insertIntoMap(a[i],1);
        frequency.PB(MP(a[i],1));
        return;
    }
    nodes maxi = query(1,1,n,i,j);
    int idx = maxi.idx;
    LL frq = 1 + (idx - i) + (j- idx) + (idx-i)*(j-idx);
    frequency.PB(MP(a[idx],frq));
//    insertIntoMap(a[idx],frq);
    createFrequencyArray(i,idx-1);
    createFrequencyArray(idx+1,j);
}

//void getFrequencyArrayFromMap(){
//    map<int,LL>::iterator it;
//    for (it=frqMap.begin();it!=frqMap.end(); it++){
////        std::cout << it.first << ": " << it.second << std::endl;
//        frequency.PB(MP(it->first,it->second));
//    }
//}

void wins(int sm , char first){
//        cout<<"\nsm = "<<sm<<endl;
    char scnd;
    if(first == 'C')
        scnd = 'D';
    else
        scnd = 'C';
    if((sm % 2))
        cout<<first;
    else
        cout<<scnd;
}


void printFrequencyArray(){
    cout<<"Frequency Array : \n";
    int sz = frequency.size();
    for(int i=0;i<sz;i++){
        cout<<frequency[i].F<<" "<<frequency[i].S<<endl;
    }
}

int main(){
    inp(n);
    inp(m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        init(1,1,n,i,i,a[i]);
    }
    
    createFrequencyArray(1,n);
    sort(frequency.begin(),frequency.end());
//    getFrequencyArrayFromMap();
//    printFrequencyArray();
    cumulativeSum[0] = frequency[0].S;
    for(int i=1;i<frequency.size();i++){
        cumulativeSum[i] = cumulativeSum[i-1] + frequency[i].S;
    }
    
    int sz = frequency.size();
    
    for(int i=0;i<m;i++){
        char sign, first;
        int k;
        LL sm = 0;
        cin>>sign>>k>>first;
        if(sign == '<'){
            int idx = floorBinarySearch(0, sz-1, k);
            while(idx >= 0 && frequency[idx].F >= k)
                idx--;
            if(idx >= 0)
            sm = cumulativeSum[idx];
            wins(sm,first);
        }
        else
        if(sign == '='){
            sm = 0;
            int idx = equalBinarySearch(0, sz-1, k);
            if(idx >= 0)
                sm = frequency[idx].S;
            wins(sm,first);
        }
        else{
            int idx = ceilingBinarySearch(0, sz-1, k);
            while(idx < sz && frequency[idx].F <= k)
                idx++;
            sm = cumulativeSum[sz-1];
            if(idx > 0 && idx <= sz)
                sm -= cumulativeSum[idx-1];
            wins(sm,first);
        }
    }
    return 0;
}
