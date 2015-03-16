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
#define MX 24

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

long MOD;
long long matrix[MX][MX], powerMatrix[MX][MX], tmp[MX][MX];
char allNodes[] = {'A','B','C','D','E','F','G','H'};
long long val[MX],finalResult[MX];
vector<char> getNextNodes(char sourceNode){
    vector<char> result;
    if(sourceNode == 'A'){
        result.PB('B');
        result.PB('D');
        result.PB('E');
    }
    if(sourceNode == 'B'){
        result.PB('A');
        result.PB('C');
        result.PB('F');
    }
    if(sourceNode == 'C'){
        result.PB('B');
        result.PB('D');
        result.PB('G');
    }
    if(sourceNode == 'D'){
        result.PB('A');
        result.PB('C');
        result.PB('H');
    }
    if(sourceNode == 'E'){
        result.PB('F');
        result.PB('A');
        result.PB('H');
    }
    if(sourceNode == 'F'){
        result.PB('E');
        result.PB('G');
        result.PB('B');
    }    if(sourceNode == 'G'){
        result.PB('F');
        result.PB('H');
        result.PB('C');
    }
    if(sourceNode == 'H'){
        result.PB('E');
        result.PB('G');
        result.PB('D');
    }
    return result;
    
}

void createMatrix(){
    int row=0;

    for(int i=0;i<sizeof(allNodes);i++){
        vector<char> parents = getNextNodes(allNodes[i]);
        
        for(int j=0;j<parents.size();j++){
            vector<char> parentOfParent = getNextNodes(parents[j]);
            
            for(int k=0;k<parentOfParent.size();k++){
                if(parentOfParent[k]!=allNodes[i]){
                    int clm = (int(parents[j])-65)*3+k;
                    matrix[row][clm]=1;
//                    cout<<"("<<allNodes[i]<<","<<parents[j]<<") -> ("<<parents[j]<<","<<parentOfParent[k]<<")\n";
                }
            }
            row++;
        }
    }
}

void print(){
    cout<<"matrix is :\n";
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++)
            cout<<powerMatrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"val is :\n";
    for(int i=0;i<MX;i++){
        cout<<val[i]<<" ";
    }
}

void init(char source){
    vector<char> parents = getNextNodes(source);
    
    for(int j=0;j<parents.size();j++){
        vector<char> parentOfParent = getNextNodes(parents[j]);
        
        for(int k=0;k<parentOfParent.size();k++){
            if(parentOfParent[k]==source){
                int row = (int(parents[j])-65)*3+k;
                val[row]=1;
            }
        }
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

long long numberOfWays(char destination){
    int row= (int(destination)-65)*3;
    long long ans = ( finalResult[row] + finalResult[row+1] +finalResult[row+2] ) % MOD;
    return ans;
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
                if(ans > MOD)
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
                if(ans > MOD)
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

int main(){
    char source,destination;
    int k;
    cin>>source>>destination>>k>>MOD;
    CLR(matrix);
    createMatrix();
    init(source);
    repeatedSquering(k-1);
    //print();
    if(k>1)
        getFinalResultMatrix();
    else
        copyValToFinalResult();
    cout<<numberOfWays(destination);
}
