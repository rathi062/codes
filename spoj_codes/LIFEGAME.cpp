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
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define Mi 100005

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;
int n;
LL MOD,l,totalLines,MX;
int totalColonies;
LL matrix[100][100],powerMatrix[100][100],tmp[100][100];
LL val[100],finalResult[100];

struct colony{
    int x,y,index;
    LL virus;
    vector<pii> nbr;
};
colony colonies[15][15];

int getLength(int i){
    if(i<=totalLines/2) return n+i;
    else return totalLines - (i-totalLines/2);
}

bool isValidPoint(int x,int y){
    if(x<0 || y<0 || x>=totalLines )
        return false;
    int len = getLength(x);
    if(y>=len)
        return false;
    return true;
}

vector<pii> getNeighbores(int i,int j){
    vector<pii> result;
    result.push_back(MP(i,j));
    if(i<n-1){
        if(isValidPoint(i-1,j-1)) result.push_back(MP(i-1,j-1));
        if(isValidPoint(i-1,j)) result.push_back(MP(i-1,j));
        if(isValidPoint(i,j-1)) result.push_back(MP(i,j-1));
        if(isValidPoint(i,j+1)) result.push_back(MP(i,j+1));
        if(isValidPoint(i+1,j)) result.push_back(MP(i+1,j));
        if(isValidPoint(i+1,j+1)) result.push_back(MP(i+1,j+1));
    }
    else
    if(i==n-1){
        if(isValidPoint(i-1,j-1)) result.push_back(MP(i-1,j-1));
        if(isValidPoint(i-1,j)) result.push_back(MP(i-1,j));
        if(isValidPoint(i,j-1)) result.push_back(MP(i,j-1));
        if(isValidPoint(i,j+1)) result.push_back(MP(i,j+1));
        if(isValidPoint(i+1,j)) result.push_back(MP(i+1,j));
        if(isValidPoint(i+1,j-1)) result.push_back(MP(i+1,j-1));
    }
    else
    if(i>n-1){
        if(isValidPoint(i-1,j)) result.push_back(MP(i-1,j));
        if(isValidPoint(i-1,j+1)) result.push_back(MP(i-1,j+1));
        if(isValidPoint(i,j-1)) result.push_back(MP(i,j-1));
        if(isValidPoint(i,j+1)) result.push_back(MP(i,j+1));
        if(isValidPoint(i+1,j)) result.push_back(MP(i+1,j));
        if(isValidPoint(i+1,j-1)) result.push_back(MP(i+1,j-1));
    }
    return result;
    
}

void createMatrix(){
    for(int i=0;i<totalLines;i++){
        int len = getLength(i);
        for(int j=0;j<len;j++){
            int x = colonies[i][j].index;
            vector<pii> nbrs = colonies[i][j].nbr;
            for(int k=0;k<nbrs.size();k++){
                int y = colonies[nbrs[k].F][nbrs[k].S].index;
                matrix[x][y]=1;
            }
        }
    }
}

void print(){
    for(int i=0;i<totalColonies;i++){
        for(int  j=0;j<totalColonies;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void getFinalResultMatrix(){
    for(int i=0;i<MX;i++){
        long long ans=0;
        for(int j=0;j<MX;j++){
            ans+=powerMatrix[i][j]*val[j];
            if(ans >= MOD)
                ans = ans%MOD;
        }
        finalResult[i]=ans;
    }
}

void copy(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            powerMatrix[i][j]=tmp[i][j];
        }
    }
}
void square(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            long long ans=0;
            for(int k=0;k<MX;k++){
                ans += powerMatrix[i][k] * powerMatrix[k][j];
                if(ans >= MOD)
                    ans = ans%MOD;
            }
            tmp[i][j]=ans;
        }
    }
    copy();
}

void multi(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            long long ans=0;
            for(int k=0;k<MX;k++){
                ans += powerMatrix[i][k] * matrix[k][j];
                if(ans >= MOD)
                    ans = ans%MOD;
            }
            tmp[i][j]=ans;
        }
    }
    copy();
}

void repeatedSquering(int n) {
    if(n<1)
        return;
    if(n==1){
        for(int i=0;i<MX;i++)
            for(int j=0;j<MX;j++)
                powerMatrix[i][j] = matrix[i][j];
        return;
    }
    if(n%2){
        repeatedSquering(n/2);
        square();
        multi();
    }
    else{
        repeatedSquering(n/2);
        square();
    }
}

void copyValToFinalResult(){
    for(int j=0;j<MX;j++){
        finalResult[j]=val[j];
    }
}

LL getTotalVirus(){
    LL result=0;
    for(int j=0;j<MX;j++){
        result += finalResult[j];
    }
    return result;
}
void printFinalResult(){
    for(int i=0;i<totalLines;i++){
        int len = getLength(i);
        for(int j=0;j<len;j++){
            cout<<finalResult[colonies[i][j].index]<<" ";
        }
        cout<<endl;
    }
}

void init(){
    CLR(matrix);
    CLR(powerMatrix);
    CLR(tmp);
    CLR(finalResult);
    CLR(colonies);
    CLR(val);
}

int main(){
    cin>>n>>MOD>>l;
    int cs = 1;
    while(!(n==0 && MOD==0 && l==0)){
    
        init();
        totalLines = 2*n-1;
        totalColonies = 3*(n*(n-1))+1;
        MX = totalColonies;
        int index=0;
        for(int i=0;i<totalLines;i++){
            int len = getLength(i);
            for(int j=0;j<len;j++){
                cin>>colonies[i][j].virus;
                colonies[i][j].index = index;
                val[index] = colonies[i][j].virus;
                index++;
                colonies[i][j].x = i;
                colonies[i][j].y = j;
                colonies[i][j].nbr = getNeighbores(i,j);
            }
        }
        createMatrix();
        repeatedSquering(l);
        getFinalResultMatrix();
        cout<<"\nCase "<<cs<<": "<<getTotalVirus();
        cs++;
        cin>>n>>MOD>>l;
    }
}



























