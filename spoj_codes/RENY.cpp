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
#define MX 1000000
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
static char buff[8000000], *ptr = buff;
inline int nextint() {
int ret = 0;
while(*ptr < '0') ptr++;
do { ret = ret * 10 + *ptr++ - '0'; } while(*ptr >= '0');
return ret;
}
struct Node{
	int st,ed,val;
}nod[MX];
static bool compare(Node a,Node b)
{
	return (a.st==b.st)?(a.ed<b.ed):(a.st<b.st);
}
int a[2*MX];
int main()
{
    int t,n,i,mx;
    fread(buff, 8000000, 1, stdin);
    t=nextint();
    while(t--)
    {
         CLR(a);
         mx=0;
		 n = nextint();
		 for(i=0;i<n;i++)
		 {
		 	  	nod[i].st = nextint(); nod[i].ed = nextint(); nod[i].val = nextint();
		 	  nod[i].ed+=nod[i].st;
		 	  mx=max(mx,nod[i].ed);
		 }
         sort(nod,nod+n,compare);
         /*cout<<"\nsorted array is : \n";
         for(i=0;i<n;i++)
         {
         	cout<<nod[i].st<<" "<<nod[i].ed<<" "<<nod[i].val<<endl;
         }*/
         int tm=mx,p=0;
         for(i=0;i<tm;i++)
         {
         	  while(p<n&&nod[p].st==i)
         	  {
         	  	 //a[i]=max(a[i],a[i-1]);
				 a[nod[p].ed]=max(a[nod[p].ed],a[nod[p].st]+nod[p].val);
				 p++; 
         	  }
         	  a[i+1]=max(a[i],a[i+1]);
         }
         /*cout<<"\nsorted array a[] is : \n";
         for(i=0;i<=tm;i++)
         {
         	cout<<a[i]<<" ";
         }*/
         printf("%d\n",a[tm]);
    }
    return 0;
}





