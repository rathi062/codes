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


using namespace std;

int n,q;
int a[MX],l[MX],r[MX],k[MX];
long long sum[11][MX];
long long fun(int ll, int rr,int kk){
    int no = (rr-ll+1)/kk;
    if((rr-ll+1)%kk > 0)
        no++;
//    cout<<"no = "<<no<<endl;
    int mxIdx = ll + (no-1)*kk;
    if(mxIdx >= n)
        mxIdx -=kk;
    long long result = sum[kk][mxIdx];
    if(ll-kk>=0)
        result -= sum[kk][ll-kk];
    return result;
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<q;i++)
        cin>>l[i]>>r[i]>>k[i];
    for(int i=1;i<=10;i++){
        for(int j=0;j<n;j++){
            if(j-i>=0)
                sum[i][j]=a[j]+sum[i][j-i];
            else
                sum[i][j]=a[j];
        }
    }
    for(int i=1;i<=10;i++){
        for(int j=0;j<n;j++){
            
            cout<<sum[i][j]<<" ";
            
        }
        cout<<endl;
    }
    for(int i=0;i<q;i++){
        cout<<fun(l[i]-1,r[i]-1,k[i])<<endl;
    }
}
