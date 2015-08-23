#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

#define PB push_back
#define LL long long
#define MX 5


using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }

LL MOD;
LL fib[MX][MX], ret[MX][MX], tmp[MX][MX],matrix[MX][MX];
LL val[MX],fR[MX];


void createMatrix(){
    LL mat[5][5] = {
        {1,1,0,0,0},
        {0,0,1,1,1},
        {3,3,0,0,0},
        {0,0,2,1,0},
        {0,0,1,0,0}
    };
    for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) matrix[i][j] = mat[i][j];
}

void init(){
    val[0]=1;
    val[1]=val[2]=val[4]=3;
    val[3]=6;
}

void fibonacci(int n)
{
    int i,j,k;
    for(i=0; i<MX; i++) for(j=0; j<MX; j++) ret[i][j] = i==j?1:0;
    while(n)
    {
        if(n&1)
        {
            for(i=0; i<MX; i++) for(j=0; j<MX; j++) tmp[i][j]=0;
            for(i=0; i<MX; i++) for(j=0; j<MX; j++) for(k=0; k<MX; k++){
                tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
                tmp[i][j]=tmp[i][j]>=MOD ? tmp[i][j]%MOD:tmp[i][j];
            }
            for(i=0; i<MX; i++) for(j=0; j<MX; j++) ret[i][j]= tmp[i][j];
        }
        for(i=0; i<MX; i++) for(j=0; j<MX; j++) tmp[i][j]=0;
        for(i=0; i<MX; i++) for(j=0; j<MX; j++) for(k=0; k<MX; k++){
            tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
            tmp[i][j]=tmp[i][j]>=MOD ? tmp[i][j]%MOD:tmp[i][j];
        }
        for(i=0; i<MX; i++) for(j=0; j<MX; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
}

void copyMatrixToFib(){
    for(int i=0;i<MX;i++) for(int j=0;j<MX;j++) fib[i][j] = matrix[i][j];
}

void getfRMT(){
    for(int i=0;i<MX;i++){
        LL ans=0;
        for(int j=0;j<MX;j++){
            ans+=ret[i][j]*val[j];
            if(ans >= MOD)
                ans = ans%MOD;
        }
        fR[i]=ans;
    }
}

LL numberOfWays(){
    LL ans = 0;
    for(int i=0;i<MX;i++){
        ans += fR[i];
        if(ans >=MOD)
            ans = ans % MOD;
    }
    return ans;
}

int main(){
    int q,k;
    inp(q);
    MOD = 1000000007;
    init();
    createMatrix();
    while(q--){
        copyMatrixToFib();
        inp(k);
        if(k==0){
            cout<<"0"<<endl;
            continue;
        }
        if(k==1){
            cout<<"4"<<endl;
            continue;
        }
        if(k==2){
            cout<<"16"<<endl;
            continue;
        }
        fibonacci(k-2);
        getfRMT();
        
        cout<<numberOfWays()<<endl;
    }
}
