

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


double getSlope(pii a,pii b){
    double result = double((a.S-b.S)/(a.F-b.F));
    return result;
}

double sqr(double a){
    return a*a;
}


double distanceBetweenTwoPoints(pii a, pdd b){
    return sqrt(sqr(a.F-b.F) + sqr(a.S-b.S));
}

ppd getLineFromTwoPoints(pii a,pii b){
    ppd result;
    if(a.F==b.F){
        result.F.F=1;
        result.F.S=0;
        result.S = a.F;
        return result;
    }
    double slope = getSlope(a,b);
    double A = slope,B = -1;
    double C = (slope*a.F - a.S);
    result.F.F=A;
    result.F.S=B;
    result.S = C;
    return result;
}

ppd getPerpendicularLine(ppd a, pdd midPoint){
    double D = a.F.S * midPoint.S - a.F.F * midPoint.F;
    ppd perpendicularLine;
    double val = (-1) * a.F.S;
    perpendicularLine.F.F = val;
    perpendicularLine.F.S = a.F.F;
    perpendicularLine.S = D;
    return perpendicularLine;
}

pdd getMidPoint(pii a, pii b){
    pdd midPoint;
    midPoint.F = double((a.F+b.F)/2);
    midPoint.S = double((a.S+b.S)/2);
    return midPoint;
}

ppd getCircleRadiusAndCenter(pii a, pii b, pii c){
    ppd line1 = getLineFromTwoPoints(a,b);
    ppd line2 = getLineFromTwoPoints(b,c);
    pdd midPoint1 = getMidPoint(a,b);
    pdd midPoint2 = getMidPoint(b,c);
    ppd perpndLine1,perpndLine2;
    perpndLine1 = getPerpendicularLine(line1,midPoint1);
    perpndLine2 = getPerpendicularLine(line2,midPoint2);
    line1 = perpndLine1;
    line2 = perpndLine2;
    double delta = line1.F.F * line2.F.S - line1.F.S * line2.F.F;
    ppd result;
    pdd point;
    if(delta==0)
    {
        return result;
    }

    point.F = (line2.F.S * line1.S - line1.F.S * line2.S)/delta;
    point.S = (line1.F.F * line2.S - line2.F.F * line1.S)/delta;
    result.F = point;
    result.S = distanceBetweenTwoPoints(a,point);
    return result;
}

int main()
{
    int n = 3;
    cout<<"enter 3 points : ";
    pii *x;
    x = new pii [n];
    for(int i=0;i<n;i++)
        cin>>x[i].F>>x[i].S;
    ppd point = getCircleRadiusAndCenter(x[0],x[1],x[2]);
    cout<<"\nintersection point is : "<<point.F.F<<", "<<point.F.S<<" , radius : "<<point.S;

    return 0;
}

