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
#define MX 100005
#define MOD 100000000

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
bool check[MX];
LL k,lmt,n;
bool fun(LL x,LL y,LL z)
{
    //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
    LL mn = min3(x,y,z);
    if(mn<0)
    {
        x+=mn*(-1);
        y+=mn*(-1);
        z+=mn*(-1);
    }
    else
    {
        x-=mn;
        y-=mn;
        z-=mn;
    }
    if((k-(x+y+z))%3)
        return 0;
    LL val = ((k-(x+y+z))/3);
    if(val<0)
        return 0;
    x+=val;
    y+=val;
    z+=val;
    //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
    if(x>lmt || y>lmt || z>lmt)
    {
        //cout<<"no\n";
        return 0;
    }
    
    return 1;
}
int main()
{
    int t;
    inp(t);
    while(t--)
    {
        LL d1,d2,x,y,z;
        inpll(n);
        inpll(k);
        inpll(d1);
        inpll(d2);
        if(n%3!=0)
        {
            cout<<"no\n";
            continue;
        }
        lmt=n/3;
        //cout<<"\nlmt = "<<lmt ;
        LL v1,v2,v3,v4;
        v1 = (k-2*d1+d2);
        v2 = (k-2*d1-d2);
        v3 = (k+2*d1-d2);
        v4 = (k+2*d1+d2);
        //cout<<"\nv1 = "<<v1<<" v2 = "<<v2<<" v3 = "<<v3<<" v4 = "<<v4;
        if(v1%3==0)
        {
            x=v1/3;
            y=x+d1;
            z=y-d2;
            //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
            if(fun(x,y,z))
            {
                cout<<"yes\n";
                continue;
            }
        }
        if(v2%3==0)
        {
            x=v2/3;
            y=x+d1;
            z=y+d2;
            //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
            if(fun(x,y,z))
            {
                cout<<"yes\n";
                continue;
            }
        }
        if(v3%3==0)
        {
            x=v3/3;
            y=x-d1;
            z=y+d2;
            //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
            if(fun(x,y,z))
            {
                cout<<"yes\n";
                continue;
            }
        }
        if(v4%3==0)
        {
            x=v4/3;
            y=x-d1;
            z=y-d2;
            //cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z;
            if(fun(x,y,z))
            {
                cout<<"yes\n";
                continue;
            }
        }
        cout<<"no\n";
        
    }
    
    return 0;
}
