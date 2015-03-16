
#include<stdio.h>
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
#define cls(a) memset(a,-1,sizeof(a))
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
#define pii pair<int,int>
#define MX 1000
#define MOD 1000000007

#define F first
#define S second
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


int crossProduct(pii a, pii b){
    return a.F*b.S - b.F*a.S;
}
//AB x AC
int  cross(pii a, pii b, pii c) {
    int abx,aby,acx,acy;
    abx = b.F - a.F;
    aby = b.S - a.S;
    acx = c.F - a.F;
    acy = c.S - a.S;
    a.F=abx;
    a.S=aby;
    b.F=acx;
    b.S=acy;
    int result = crossProduct(a,b);
    return result;
}

//triangle area form by AB and AC
double  area(pii a, pii b, pii c) {
    int cros = cross(a,b,c);
    double result = double(cros/2);
    return result;
}


int main()
{
    int n;
    cout<<"enter number of points : ";
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    double polygonArea = 0.0;
    pii a,b,c;
    a.F = x[0];
    a.S = y[0];
    for(int i=1;i<n-1 && n>2;i++){
        b.F = x[i];
        b.S = y[i];
        c.F = x[i+1];
        c.S = y[i+1];
        polygonArea += area(a,b,c);
    }
    cout<<"area is : "<<polygonArea;
    return 0;
}
