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
#define MX 10000009
#define pii pair<int,int>

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
/*
 * Complete the function below.
 */
vector < int > nextTallerBuildingHeight(vector < int > buildingHeights) {
    
    vector<int> result (buildingHeights.begin() ,buildingHeights.end());
    int l=buildingHeights.size();
    int nxtIdx[l];

    
    result[l-1] = -1;
    nxtIdx[l-1] = l;
    
    for(int i=l-2;i>=0;i--){
        int j=i+1;
        int res = -1;
        while(j<l && j >= 0){
            
            if(buildingHeights[j] > buildingHeights[i]){
                res = j;
                nxtIdx[i] = j;
                break;
            }
            j = nxtIdx[j];
        }
        if(res==-1){
            nxtIdx[i] = l;
            result[i] = -1;
        }
        else
        result[i] = buildingHeights[nxtIdx[i]];
    }
    return result;
}
int main() {
    vector < int > res;
    
    int _buildingHeights_size;
    cin >> _buildingHeights_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _buildingHeights;
    int _buildingHeights_item;
    for(int _buildingHeights_i=0; _buildingHeights_i<_buildingHeights_size; _buildingHeights_i++) {
        cin >> _buildingHeights_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _buildingHeights.push_back(_buildingHeights_item);
    }
    
    res = nextTallerBuildingHeight(_buildingHeights);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }
    
    return 0;
}
