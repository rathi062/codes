#include<iostream>
#include<string.h>
#include<queue>
#include<stdio.h>

using namespace std;
#define MX 30
#define MOD 1000000007
#define pii pair<int,int>
#define F first 
#define S second 
#define pip pair<int,pii>

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
char v[MX][MX][MX];
int ver[MX][MX][MX],C,R,K;
pip fst,idx;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};

int main()
{
	int x,y,z,x1,y1,z1,b=1,cnt=1;
	inp(C);
	inp(R);	
	inp(K);
	while(C!=0&&R!=0&&K!=0)
	{
		for(int k=0;k<K;k++)
		for(int i=0;i<R;i++)
			scanf("%s",&v[k][i]);
		queue<pip  > q;
		if(!(R==1&&C==1))
		q.push(pip(0,pii(0,0)));
		v[0][0][0]='1';
		ver[0][0][0]=0;
		b=1;
		while(!q.empty())
		{
			idx=q.front();
			q.pop();
			x=idx.S.F;
			y=idx.S.S;
			z=idx.F;
				
			z1=(z+1)%K;
			for(int k=0;k<5;k++)
			{
				x1=x+dx[k];
				y1=y+dy[k];
				if((x1<R||x1>=0)&&(y1<C&&y1>=0))
				{
					if(v[z1][x1][y1]=='0')
					{
						v[z1][x1][y1]='1';
						ver[z1][x1][y1]=ver[z][x][y]+1;
						if(x1==R-1&&y1==C-1)
						{
							b=0;
							break;
						}
						q.push(pip(z1,pii(x1,y1)));
					}
				}
			}
			if(!b)
			break;					
		}
		if(b)
		printf("Case %d: Luke and Leia cannot escape.\n",cnt++);
		else
		printf("Case %d: Luke and Leia can escape in %d steps.\n",cnt++,ver[z][R-1][C-1]);
		inp(C);
		inp(R);
		inp(K);
	}
	return 0;
}


