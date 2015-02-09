

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
#define pdd pair<double,double>
#define ppd pair<pair<double,double>,double>
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


ppd getPerpendicularLine(ppd a, pdd midPoint){
    double D = a.F.F * midPoint.S - a.F.S * midPoint.F  ;
    ppd perpendicularLine;
    double val = (-1) * a.F.S;
    perpendicularLine.F.F = val;
    perpendicularLine.F.S = a.F.F;
    perpendicularLine.S = D;
    return perpendicularLine;
}

pdd getIntersectionPoint(ppd line1,ppd line2){
    double delta = line1.F.F * line2.F.S - line1.F.S * line2.F.F;
    pdd point;
    if(delta==0)
    {
        return point;
    }
    
    point.F = (line2.F.S * line1.S - line1.F.S * line2.S)/delta;
    point.S = (line1.F.F * line2.S - line2.F.F * line1.S)/delta;
    return point;
}

pdd getReflection(ppd line1, pdd point){
    ppd perpndLine1;
    perpndLine1 = getPerpendicularLine(line1,point);
    pdd intersectionPoint = getIntersectionPoint(line1,perpndLine1);
    pdd reflectionPoint;
    reflectionPoint.F = intersectionPoint.F - (point.F - intersectionPoint.F);
    reflectionPoint.S = intersectionPoint.S - (point.S - intersectionPoint.S);
    return reflectionPoint;
}

int main()
{
    cout<<"enter A,B,C for line : ";
    double a,b,c,x,y;
    cin>>a>>b>>c;
    cout<<"enter point X : ";
    cin>>x>>y;
    ppd line ;
    line = make_pair(make_pair(a,b),c);
    pdd point;
    point = make_pair(x,y);
    point = getReflection(line,point);
    cout<<"\nintersection point is : "<<point.F<<", "<<point.S;
    
    return 0;
}

