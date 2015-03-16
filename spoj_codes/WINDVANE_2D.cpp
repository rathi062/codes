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
#include<conio.h>
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
    
void insert(int idx, int idy, int stx, int sty, int edx, int edy, int x1, int x2, int y1, int y2, int val)
{
    //cout<<"\nstx = "<<stx<<" edx = "<<edx<<" sty = "<<sty<<" edy = "<<edy<<" x1 = "<<x1<<" x2 = "<<x2;
    //getch();
    if(stx>=x1&&edx<=x2)
    {
    	//cout<<"\nnow for y\n";
        if(sty>=y1&&edy<=y2)
		{
			nod[idx][idy]+=val;
        	return;
        }
        int lft=idy<<1, rgt=lft+1;
    	int mid=(sty+edy)>>1;
    	if(y2<=mid) insert(idx,lft,stx,sty,edx,mid,x1,x2,y1,y2,val);
    	else if(y1>mid) insert(idx,rgt,stx,mid+1,edx,edy,x1,x2,y1,y2,val);
    	else
    	{
        	insert(idx,lft,stx,sty,edx,mid,x1,x2,y1,mid,val);
        	insert(idx,rgt,stx,mid+1,edx,edy,x1,x2,mid+1,y2,val);
    	}
    	return;
	}
         
    int lft=idx<<1, rgt=lft+1;
    int mid=(stx+edx)>>1;
    if(x2<=mid) insert(lft,idy,stx,sty,mid,edy,x1,x2,y1,y2,val);
    else if(x1>mid) insert(rgt,idy,mid+1,sty,edx,edy,x1,x2,y1,y2,val);
    else
    {
        insert(lft,idy,stx,sty,mid,edy,x1,mid,y1,y2,val);
        insert(rgt,idy,mid+1,sty,edx,edy,mid+1,x2,y1,y2,val);
    }
    return;
}

int query(int idx, int idy, int stx, int sty, int edx, int edy, int x1, int x2, int y1, int y2, int val)
{
    //cout<<"\nstx = "<<stx<<" edx = "<<edx<<" sty = "<<sty<<" edy = "<<edy<<" x1 = "<<x1<<" x2 = "<<x2;
    //getch();
    if(stx==x1&&edx==x2)
    {
    	//cout<<"\nfor y \n";
        if(sty==y1&&edy==y2)
		return nod[idx][idy]+val;
		
        int lft=idy<<1, rgt=lft+1;
    	int mid=(sty+edy)>>1;
    	if(y2<=mid) return query(idx,lft,stx,sty,edx,mid,x1,x2,y1,y2,val+nod[idx][idy]);
    	else if(y1>mid) return query(idx,rgt,stx,mid+1,edx,edy,x1,x2,y1,y2,val+nod[idx][idy]);
    	else
    	{
    		int l,r,tmp;
        	l=query(idx,lft,stx,sty,edx,mid,x1,x2,y1,mid,val+nod[idx][idy]);
        	r=query(idx,rgt,stx,mid+1,edx,edy,x1,x2,mid+1,y2,val+nod[idx][idy]);
        	tmp=l+r;
        	return tmp;
    	}
	}
        
    int lft=idx<<1, rgt=lft+1;
    int mid=(stx+edx)>>1;
    if(x2<=mid) return query(lft,idy,stx,sty,mid,edy,x1,x2,y1,y2,val+nod[idx][idy]);
    else if(x1>mid)return query(rgt,idy,mid+1,sty,edx,edy,x1,x2,y1,y2,val+nod[idx][idy]);
    else
    {
    	int l,r,tmp;
        l=query(lft,idy,stx,sty,mid,edy,x1,mid,y1,y2,val+nod[idx][idy]);
        r=query(rgt,idy,mid+1,sty,edx,edy,mid+1,x2,y1,y2,val+nod[idx][idy]);
        tmp=l+r;
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
			insert(1,1,0,0,m-1,n-1,x1-1,x2-1,y1-1,y2-1,d);
		}
		else
		{
			//cout<<"\nquery ";
			inp(x1);
			inp(y1);
			ans=query(1,1,0,0,m-1,n-1,x1-1,x1-1,y1-1,y1-1,0);
			//cout<<"\nans = "<<ans;
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
