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

int sqr(int a){
    return a*a;
}

double norm(pii a){
    return sqrt(sqr(a.F)+sqr(a.S));
}

double distance(pii a,pii b){
    int abx,aby;
    abx = b.F - a.F;
    aby = b.S - a.S;
    a.F=abx;
    a.S=aby;
    double result = norm(a);
    return result;
}


int dotProduct(pii a,pii b){
    return a.F*b.F + a.S*b.S;
}

//AB . BC
int  dot(pii a, pii b, pii c) {
    int abx,aby,bcx,bcy;
    abx = b.F - a.F;
    aby = b.S - a.S;
    bcx = c.F - b.F;
    bcy = c.S - b.S;
    a.F=abx;
    a.S=aby;
    b.F=bcx;
    b.S=bcy;
    int result = dotProduct(a,b);
    return result;
}


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

//cos(0) between AB and AC
double  cos(pii a, pii b, pii c) {
    int abx,aby,acx,acy;
    abx = b.F - a.F;
    aby = b.S - a.S;
    acx = c.F - a.F;
    acy = c.S - a.S;
    a.F=abx;
    a.S=aby;
    b.F=acx;
    b.S=acy;
    int dot = dotProduct(a,b);
    double aMod = norm(a);
    double bMod = norm(b);
    double result = double(dot/(aMod*bMod));
    return result;
}

//triangle area form by AB and AC
double  area(pii a, pii b, pii c) {
    int cros = cross(a,b,c);
    double result = double(cros/2);
    return result;
}

//Distance of point C to line AB
double  linePointDistance(pii a, pii b, pii c, bool isSegment) {
    double dist = cross(a,b,c)/distance(a,b);
    if(isSegment){
        int dot1 = dot(a,b,c);
        if(dot1 > 0 ) return distance(b,c);
        int dot2 = dot(b,a,c);
        if(dot2 > 0 ) return distance(a,c);
    }
    return abs(dist);
}


int main()
{
    pii a,b,c;
    cout<<"\nenter point a ";
    cin>>a.F>>a.S;
    cout<<"\nenter point b ";
    cin>>b.F>>b.S;
    cout<<"\nenter point c ";
    cin>>c.F>>c.S;
    cout<<"\ndot product is : "<<dot(a,b,c);
	cout<<"\ncross product is : "<<cross(a,b,c);
	cout<<"\ncos(0) is : "<<cos(a,b,c);
	cout<<"\narea is : "<<area(a,b,c);
	cout<<"\ndistance of a from AB as line is : "<<linePointDistance(a,b,c,0);
	cout<<"\ndistance of a from AB as segment is : "<<linePointDistance(a,b,c,1);
	return 0;
}
