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
#define MX 105
#define MOD 1000000007

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
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
char s[5];
bool ch[2][MX];
int num[2];
struct trn{
	int idx,val;
}at[MX],bt[MX];

int fun()
{
	int h=(s[0]-48)*10+(s[1]-48);
	int m=(s[3]-48)*10+(s[4]-48);
	return (h*60+m);
}
int compare(const trn a,const trn b)
{
	return (a.idx==b.idx)?(a.val<b.val):(a.idx<b.idx);
}

int main()
{
    int t=0,m,a,b,w,cnt=1;
    inp(t);
    while(t--)
    {
    	CLR(num);
    	CLR(ch);
    	inp(w);
    	inp(a);
    	inp(b);
    	for(int i=0;i<a;i++)
    	{
  			scanf("%s",&s);
			at[i].idx=fun();
			scanf("%s",&s);
			at[i].val=fun()+w;  		
    	}
    	for(int i=0;i<b;i++)
    	{
  			scanf("%s",&s);
			bt[i].idx=fun();
			scanf("%s",&s);
			bt[i].val=fun()+w;  		
    	}
    	sort(at,at+a,compare);
    	sort(bt,bt+b,compare);
    	/*for(int i=0;i<a;i++)
    	cout<<at[i].idx<<" "<<at[i].val<<endl;
    	cout<<endl;
    	for(int i=0;i<b;i++)
    	cout<<bt[i].idx<<" "<<bt[i].val<<endl;
    	cout<<endl;*/
    	
    	int i,j,start;
    	for( i=0,j=0;i<a&&j<b;)
    	{
    		start=compare(at[i],bt[j]);
    		num[start]++;
    		if(start==1)
    		ch[1][i]=1;
    		else
    		ch[0][j]=1;
    		/*if(start==1)
    		cout<<"\nat = "<<i;
    		else
    		cout<<"\nbt = "<<j;*/
    		for(int x=i,y=j;x<a&&y<b;)
    		{
    			if(start==1)
    			{
    				if( ch[0][y]==0 && at[x].val<=bt[y].idx )
    				{
    					//cout<<"\nbt = "<<y;
    					start=0;
    					ch[0][y]=1;
    				}
    				else
    				y++;
    			}
    			else
    			{
    				if( ch[1][x]==0 && at[x].idx>=bt[y].val )
    				{
    					//cout<<"\nat = "<<x;
    					start=1;
    					ch[1][x]=1;
    				}
    				else
    				x++;
    			}
    		}
    		while(ch[1][i]){i++;}
    		//cout<<"\ni = "<<i;
    		while(ch[0][j]){j++;}
    		//cout<<"\nj = "<<j;
    	}
    	for(i;i<a;i++)
    	if(ch[1][i]==0)
    	num[1]++;
    	for(j;j<b;j++)
    	if(ch[0][j]==0)
		num[0]++;
    	printf("Case #%d: %d %d\n",cnt++,num[1],num[0]);
    }
    return 0;
}
