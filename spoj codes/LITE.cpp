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
#define MX 100000
#define MOD 1000000007

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
const int MAX = 200064, BUFF = 128, PARAM = 4;
static int *readln() 
{
   static char buff[BUFF], *p;
   static int param[PARAM];
   int idx = 0;
   fgets(buff, 128, stdin);
   p = strtok(buff, " ");
   while(p)
   {
       param[idx++] = atoi(p);
       p = strtok(0, " ");
   }
   return param;
}
struct Node{
       int total,state;
       } nod[MAX];

void insert(int idx, int st, int ed, int s, int e)
{
    if(st==s&&ed==e)
    {
        nod[idx].state^=1;
        nod[idx].total=ed-st+1-nod[idx].total;
        return;
    }

    int lft=idx<<1, rgt=lft+1;
    int mid=(st+ed)>>1;
    if(e<=mid) insert(lft, st, mid, s, e);
    else if(s>mid) insert(rgt, mid+1, ed, s, e);
    else
    {
        insert(lft, st, mid, s, mid);
        insert(rgt, mid+1, ed, mid+1, e);
    }
    if(nod[idx].state) 
    nod[idx].total=ed-st+1-nod[lft].total-nod[rgt].total;
    else
    nod[idx].total=nod[lft].total+ nod[rgt].total ;
    return;
}
Node query(int idx, int st , int ed, int s, int e)
{
    if(st==s && ed==e) return nod[idx];
    int lft=idx<<1,rgt=lft+1,mid=(st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e);
    else
    {
         Node tmp;
         tmp.total = query(lft, st, mid, s, mid).total;
         tmp.total+= query(rgt, mid+1, ed, mid+1, e).total;
         return tmp;
    }
}

int main()
{
    int n, q, st, ed,t,*param;
      	param = readln();
       n = param[0];
        q = param[1];
      while(q--)
      {
        param=readln();
        t=param[0],st=param[1],ed=param[2];
        switch(t){
           case 1: printf("%d\n",query(1, 0, n-1, st-1, ed-1).total);break;
           case 0: insert(1,0,n-1,st-1,ed-1);break;
           }
      }
    return 0;
}


