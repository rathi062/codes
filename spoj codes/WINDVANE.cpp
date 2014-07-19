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
#define MX 1001
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
int nod[MX*4][MX*4];
char a[MX][MX];
bool lazy[4*MX];

    
void insert(int idx, int st, int ed, int s, int e, int val,int i)
{
    //cout<<"\nst = "<<st<<" ed = "<<ed;
    if(st>=s&&ed<=e)
    {
        nod[i][idx]+=val;
        return;
    }  
    int lft=idx<<1, rgt=lft+1;
    int mid=(st+ed)>>1;
    if(e<=mid) insert(lft, st, mid, s, e, val,i);
    else if(s>mid) insert(rgt, mid+1, ed, s, e, val,i);
    else
    {
        insert(lft, st, mid, s, mid, val,i);
        insert(rgt, mid+1, ed, mid+1, e, val,i);
    }
    return;
}

int query(int idx, int st , int ed, int s, int e,int val,int i)
{
	//cout<<"\nst = "<<st<<" ed = "<<ed<<" val = "<<val;
    if(st==s && ed==e)
		 return nod[i][idx]+val;
    int lft=idx<<1,rgt=lft+1;
    int mid=(st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e,val+nod[i][idx],i);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e,val+nod[i][idx],i);
    else
    {
         int l, r, tmp;
         l = query(lft, st, mid, s, mid,val+nod[i][idx],i);
         r = query(rgt, mid+1, ed, mid+1, e,val+nod[i][idx],i);
         tmp = l + r;
         return tmp;
    }
}
int main()
{
	int m,n,r,i,q,cd,x1,x2,y2,y1,d,ans;
	char ch[2],dir[]="WSEN";
	inp(m);
	inp(n);
	for(i=0;i<m;i++)
	scanf("%s",a[i]);
	inp(q);
	CLR(nod);
	while(q--)
	{
		scanf("%s",ch);
		if(ch[0]=='C')
		{
			//cout<<"\ninsert ";
			inp(x1);
			inp(y1);
			inp(x2);
			inp(y2);
			inp(d);
			if(d==0)
			d=-1;
			for(i=x1;i<=x2;i++)
			insert(1,0,n-1,y1-1,y2-1,d,i-1);
		}
		else
		{
			//cout<<"\nquery ";
			inp(x1);
			inp(y1);
			ans=query(1,0,n-1,y1-1,y1-1,0,x1-1);
			r=ans%4;
			if(a[x1-1][y1-1]=='N')
			cd=3;
			else
			if(a[x1-1][y1-1]=='E')
			cd=2;
			else
			if(a[x1-1][y1-1]=='S')
			cd=1;
			else
			cd=0;
			cd+=r;
			if(cd<0)
			cd+=4;
			cd=cd%4;
			printf("%c\n",dir[cd]);
		}
	}
	
	return 0;
}
