
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
#define MOD 1000003

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
	int order,n,ans;
}nod[1002];
int dp[2][MX];
int compare(Node a,Node b)
{
	return a.n<b.n;
}
int compare1(Node a,Node b)
{
	return a.order<b.order;
}
int main()
{
    int k,l,t,n=0,m=0,r,cs=1,i,j,p;
    inp(t);
    for( i=0;i<t;i++)
    {	
		inp(nod[i].n);
		nod[i].order=i;
	}	
    sort(nod,nod+t,compare);
    l=nod[t-1].n;
    //cout<<"\nl = "<<l;
    for( i=l;i>0;i--)
    dp[0][i]=1;
    /*for(k=l;k>0;k--)
    cout<<dp[0][k]<<" ";
    cout<<endl;*/
    p=0;
    while(nod[p].n==1)
    {
    	nod[p].ans=1;
    	p++;
    }
    for(i=2;i<=l;i++)
    {
    	if(i%2==0)
    	{
    		dp[1][l]=1;
    		for(j=l-1;j>0;j--)
    		{
    			dp[1][j]=dp[1][j+1]+dp[0][j]+dp[0][j+1];
    			if(dp[1][j]>=MOD)
				dp[1][j]%=MOD;
    		}
    		/*for(k=l;k>0;k--)
    		cout<<dp[1][k]<<" ";
    		cout<<endl;*/
    		while(nod[p].n==i)
    		nod[p++].ans=dp[1][l-i+1];
    	}
    	else
    	{
    		dp[0][l]=1;
    		for(j=l-1;j>0;j--)
    		{
    			dp[0][j]=dp[0][j+1]+dp[1][j]+dp[1][j+1];
    			if(dp[0][j]>=MOD)
				dp[0][j]%=MOD;
    		}
    		/*for(k=l;k>0;k--)
    		cout<<dp[0][k]<<" ";
    		cout<<endl;*/
    		while(nod[p].n==i)
    		nod[p++].ans=dp[0][l-i+1];
    	}
    }
    sort(nod,nod+t,compare1);
	for(i=0;i<t;i++)
	printf("%d\n",nod[i].ans);
	return 0;
}

