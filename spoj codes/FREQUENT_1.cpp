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
    int n,f,ln,lf,rn,rf;
}nod[MX*4];
int a[MX];
char lazy_value[4*MX];
bool lazy[4*MX];
void insert(int idx,int st,int ed)
{
     if(st==ed)
     {
     	nod[idx].n=a[st];
     	nod[idx].ln=a[st];
     	nod[idx].rn=a[st];
     	nod[idx].f = nod[idx].lf = nod[idx].rf = 1;
     	/*
		 cout<<"\nidx = "<<idx<<" st = "<<st<<" ed = "<<ed;
     	cout<<"\nn = "<<nod[idx].n<<" f = "<<nod[idx].f;
     	cout<<"\nln = "<<nod[idx].ln<<" lf = "<<nod[idx].lf;
     	cout<<"\nrn = "<<nod[idx].rn<<" rf = "<<nod[idx].rf;
		*/ 
		 return ;
     }
     int lft,rgt,mid=(st+ed)/2,fr;
     lft=idx<<1;
     rgt=lft+1;
     insert(lft,st,mid);
     insert(rgt,mid+1,ed);
     if(nod[lft].rn==nod[rgt].ln)
     {
     	fr=nod[lft].rf+nod[rgt].lf;
     	nod[idx].f=max3(fr,nod[lft].f,nod[rgt].f);
     	if(nod[lft].f==nod[idx].f)
     	nod[idx].n=nod[lft].n;
     	else
     	if(nod[rgt].f==nod[idx].f)
     	nod[idx].n=nod[rgt].n;
     	else
     	nod[idx].n=nod[lft].rn;
     	
		if(nod[lft].ln==nod[rgt].ln)
		{
			nod[idx].ln=nod[lft].ln;
			nod[idx].lf=nod[lft].lf+nod[rgt].lf;
		}
		else
		{
			nod[idx].ln=nod[lft].ln;
			nod[idx].lf=nod[lft].lf;
		}
		
		if(nod[rgt].rn==nod[lft].rn)
		{
			nod[idx].rn=nod[rgt].rn;
			nod[idx].rf=nod[lft].rf+nod[rgt].rf;
		}
		else
		{
			nod[idx].rn=nod[rgt].rn;
			nod[idx].rf=nod[rgt].rf;
		}
     }
     else
     {
     	nod[idx].f=max(nod[lft].f,nod[rgt].f);
     	if(nod[lft].f==nod[idx].f)
     	nod[idx].n=nod[lft].n;
     	else
     	if(nod[rgt].f==nod[idx].f)
     	nod[idx].n=nod[rgt].n;
     	
			nod[idx].ln=nod[lft].ln;
			nod[idx].lf=nod[lft].lf;
			
			nod[idx].rn=nod[rgt].rn;
			nod[idx].rf=nod[rgt].rf;
     }
     /*
     	cout<<"\nidx = "<<idx<<" st = "<<st<<" ed = "<<ed;
     	cout<<"\nn = "<<nod[idx].n<<" f = "<<nod[idx].f;
     	cout<<"\nln = "<<nod[idx].ln<<" lf = "<<nod[idx].lf;
     	cout<<"\nrn = "<<nod[idx].rn<<" rf = "<<nod[idx].rf;
	 */
	 return ;
}
Node query(int idx, int st , int ed, int s, int e)
{
    if(st==s && ed==e) return nod[idx];
    int lft=idx<<1,rgt=lft+1,mid=(st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e);
    else
    {
         int fr;
		 Node tmp,l,r;
         l = query(lft, st, mid, s, mid);
         r = query(rgt, mid+1, ed, mid+1, e);
         if(l.rn==r.ln)
     	 {
     		fr=l.rf+r.lf;
     		tmp.f=max3(fr,l.f,r.f);
     		if(l.f==tmp.f)
     		tmp.n=l.n;
     		else
     		if(r.f==tmp.f)
     		tmp.n=r.n;
     		else
     		tmp.n=l.rn;
     	
			if(l.ln==r.ln)
			{
				tmp.ln=l.ln;
				tmp.lf=l.lf+r.lf;
			}
			else
			{
				tmp.ln=l.ln;
				tmp.lf=l.lf;
			}
		
			if(r.rn==l.rn)
			{
				tmp.rn=r.rn;
				tmp.rf=l.rf+r.rf;
			}
			else
			{
				tmp.rn=r.rn;
				tmp.rf=r.rf;
			}
		}
     	else
     	{
     		tmp.f=max(l.f,r.f);
     		if(l.f==tmp.f)
     		tmp.n=l.n;
     		else
     		tmp.n=r.n;
     	
			tmp.ln=l.ln;
			tmp.lf=l.lf;
			
			tmp.rn=r.rn;
			tmp.rf=r.rf;
     	}
	 return tmp;
    }
}int main()
{
    int n, i, r,q, cnt, st, ed,w;
    inp(n);
    while(n!=0)
    {
    
    	inp(q);
    	for(i=0;i<n;i++)
    	inp(a[i]);
    	insert(1,0,n-1);
    	while(q--)
    	{
       		inp(st);
       		inp(ed);
       		printf("%d\n",query(1,0,n-1,st-1,ed-1).f);
    	}
    	inp(n);
    }
    return 0;
}


