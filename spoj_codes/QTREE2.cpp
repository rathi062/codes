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

int n;
struct edge{
    int s,e,val;
} edges[MX];

vector<pii> graph[MX];
int E[2*MX], L[2*MX], H[MX], check[MX], eIn, D[MX], P[MX], V[MX];

struct node{
    int idx,lvl;
}nod[4*MX];

void update_node(int in,int val,int idx)
{
    if(nod[in].lvl > val){
        nod[in].lvl = val;
        nod[in].idx = idx;
    }
}

void segment_init(int in,int st,int nd,int i,int j,int val)
{
    
    int mid,l,r;
    if(st==i&&nd==j)
    {
        update_node(in,val,i);
        return ;
    }
    mid=(st+nd)/2;
    l=in*2;
    r=l+1;
    if(j<=mid)
        segment_init(l,st,mid,i,j,val);
    else
        segment_init(r,mid+1,nd,i,j,val);
    update_node(in, nod[l].lvl, nod[l].idx);
    update_node(in, nod[r].lvl, nod[r].idx);
    return ;
}
node query(int in,int st,int nd,int i,int j)
{
    int l,r,mid;
    
    if(st>=i&&nd<=j)
        return nod[in];
    if(st>=nd)
        return nod[in];
    
    mid=(st+nd)/2;
    l=in*2;
    r=l+1;
    if(j<=mid)
        return query(l,st,mid,i,j);
    else
        if(i>mid)
            return query(r,mid+1,nd,i,j);
        else
        {
            node p1,p2,tmp;
            p1=query(l,st,mid,i,j);
            p2=query(r,mid+1,nd,i,j);
            if(p1.lvl < p2.lvl){
                tmp.lvl = p1.lvl;
                tmp.idx = p1.idx;
            }
            else{
                tmp.lvl = p2.lvl;
                tmp.idx = p2.idx;
            }
            return tmp;
        }
}


void eulerTour(int idx, LL dist, int lvl){
    for(int i=0; i<graph[idx].size(); i++){
        int nxt = graph[idx][i].first;
        if(check[nxt]) continue;
        
        E[eIn] = nxt;
        H[nxt] = eIn;
        check[nxt] = 1;
        L[eIn] = lvl+1;
        D[nxt] = dist + graph[idx][i].second;
        P[nxt] = idx;
        V[nxt] = graph[idx][i].second;
        eIn++;
        eulerTour(nxt, D[nxt], lvl+1);
        E[eIn] = idx;
        L[eIn] = lvl;
        eIn++;
    }
}

void createSegmentTree(){
    CLR(nod);
    for(int i=1;i<4*eIn;i++){
        nod[i].idx = nod[i].lvl = 2*MX;
    }
    for(int i=1;i<eIn;i++){
        segment_init(1, 1, eIn-1, i, i, L[i]);
    }
}

void preprocessing(){
    CLR(check);
    CLR(P);
    CLR(H);
    CLR(L);
    CLR(V);
    H[1]=1;
    check[1]=1;
    L[1]=0;
    E[1]=1;
    D[1]=0;
    P[1]=0;
    V[1]=0;
    eIn = 2;
    eulerTour(1,0,0);
    createSegmentTree();
}

vector<int> getPathFromXtoY(int x, int y){
    vector<int> path;
    while(x != y && x != 0){
        path.PB(x);
        x = P[x];
    }
    if(x != 0)
        path.PB(x);
    int size = path.size();
    if(path[size-1] == y)
        return path;
    vector<int> path1 = getPathFromXtoY(y, 1);
    int size1 = path1.size();
    for(int i = size1-2; i >=0; i--){
        path.PB(path1[i]);
    }
    return path;
}

vector<int> getPath(int x, int y,int num){

    vector<int> path;
    if(num == y)
        path = getPathFromXtoY(x,y);
    else{
        path = getPathFromXtoY(x, num);
        vector<int> path1 = getPathFromXtoY(y, num);
        int size1 = path1.size();
        for(int i = size1-2; i >=0; i--){
            path.PB(path1[i]);
        }
    }
    return path;
}

void getDistance() {
    int s,e;
    inp(s);
    inp(e);
    if(L[s] < L[e]){
        swap(s,e);
    }
    int a = H[e];
    int b = H[s];
    if(a>b)
        swap(a,b);
    node LCA = query(1, 1, eIn-1, a,  b);
    int num = E[LCA.idx];
    int cost = D[s] + D[e] - 2*D[num];
    cout<<cost<<endl;
}

void getKthNumber() {
    int s,e,k,ss,ee;

    inp(ss);
    inp(ee);
    inp(k);
    s=ss;
    e=ee;
    if(L[s] < L[e]){
        swap(s,e);
    }
    int a = H[e];
    int b = H[s];
    if(a>b)
        swap(a,b);
    node LCA = query(1, 1, eIn-1, a,  b);
    int num = E[LCA.idx];
    vector<int> path = getPath(s,e,num);

//    for(int i=0;i<path.size();i++){
//        cout<<path[i]<<" ";
//    }
//    cout<<endl;

    if(path[0] != ss){
        reverse(path.begin(),path.end());
    }
    cout<<path[k-1]<<endl;
}

void printArrays(){
    cout<<"\nE : ";
    for(int i=1;i<eIn;i++){
        cout<<E[i]<<" ";
    }
    cout<<"\nL : ";
    for(int i=1;i<eIn;i++){
        cout<<L[i]<<" ";
    }
    cout<<"\nD : ";
    for(int i=1;i<=n;i++){
        cout<<D[i]<<" ";
    }
    cout<<"\nH : ";
    for(int i=1;i<=n;i++){
        cout<<H[i]<<" ";
    }
    cout<<"\nP : ";
    for(int i=1;i<=n;i++){
        cout<<P[i]<<" ";
    }
    cout<<"\nV : ";
    for(int i=1;i<=n;i++){
        cout<<V[i]<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        CLR(graph);
        for(int i=0;i<n-1;i++){
            inp(edges[i].s);
            inp(edges[i].e);
            inp(edges[i].val);
            graph[edges[i].s].push_back( MP(edges[i].e, edges[i].val ));
            graph[edges[i].e].push_back( MP(edges[i].s, edges[i].val ));
        }
        preprocessing();
//        printArrays();
        string s;
        cin>>s;
        while(s != "DONE"){
            if(s == "DIST")
                getDistance();
            else
                getKthNumber();
            cin>>s;
        }
        cout<<endl;
    }
}