
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
#define MX 1000001
#define MOD 1000000007

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

struct Node{	
       int idx,st,ed;
       }query[MX];
using namespace std;
int a[MX],bit[1<<20],last[MX],an[MX],bnum;
bool ch[MX]; 
int compare(const void *a,const void* b)
{
     Node *p1=(Node*)a;
     Node *p2=(Node*)b;
     return p1->ed - p2->ed;
}
void init(int n)
{
     for(bnum=1;bnum<n;bnum*=2);
}
void remove(int n)
{
     int idx=n;
     //cout<<"\nremoving ";
     while(1)
     {
         bit[idx]--;
         if(idx==bnum)
         break;
         //cout<<"\nidx = "<<idx<<" bit = "<<bit[idx];
         idx+=idx & (-idx);
     }
}
void add(int n)
{
     int idx=n;
     while(1)
     {
         bit[idx]++;
         if(idx==bnum)
         break;
         //cout<<"\nidx = "<<idx<<" bit = "<<bit[idx];
         idx+=idx&(-idx);
     }
}

int before(int idx)
{
    int res=0;
    while(idx>0)
    {
    	res+=bit[idx];
    	idx-=idx&(-idx);
    }
    return res;
}
int main()
{
    int n,idx,p,val,q,x,y,ans;
    CLR(a);
    CLR(bit);
    inp(n);
    for(int i=1;i<=n;i++)
    inp(a[i]);
    init(n);
    //cout<<"\nbnum = "<<bnum;
    inp(q);
    for(int i=0;i<q;i++)
    {
            inp(x);
            inp(y);
            query[i]=(Node){i,x,y};
    }
    qsort(query,q,sizeof(Node),compare);
    int j=0;
    for(int i=0;i<q;i++)
    {
    	    //cout<<"\nquery.ed = "<<query[i].ed;
            while(j<query[i].ed)
            {
                j++;
                if(last[a[j]])
                remove(last[a[j]]);
                add(j);
                last[a[j]]=j;
                /*cout<<"\nat j = "<<j<<" ";
                for(int l=0;l<=bnum;l++)
                {
                	cout<<bit[l]<<" ";
                }
                cout<<endl;
                //cout<<"\nj = "<<j<<" bit[1] = "<<bit[1];*/
            }
            an[query[i].idx]=bit[bnum]-before(query[i].st-1);
    }
    for(int i=0;i<q;i++)
    {
    	printf("%d\n",an[i]);
    }
    
    return 0;
}
