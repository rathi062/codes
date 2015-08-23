#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

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

long MOD;
bool check[1000000];
LL MT[MX][MX], pM[MX][MX], tmp[MX][MX], pre[10000000][MX][MX];
LL val[MX],fR[MX];
int cnt=0;
map<int,int> m;
void createMT(){
    LL mat[5][5] = {
        {1,1,0,0,0},
        {0,0,1,1,1},
        {3,3,0,0,0},
        {0,0,2,1,0},
        {0,0,1,0,0}
    };
    for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) MT[i][j] = mat[i][j];
}

void init(){
    val[0]=1;
    val[1]=val[2]=val[4]=3;
    val[3]=6;
}

void getfRMT(){
    for(int i=0;i<MX;i++){
        LL ans=0;
        for(int j=0;j<MX;j++){
            ans+=pM[i][j]*val[j];
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


void copy(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            pM[i][j]=tmp[i][j];
        }
    }
}
void square(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            LL ans=0;
            for(int k=0;k<MX;k++){
                ans += pM[i][k] * pM[k][j];
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
            LL ans=0;
            for(int k=0;k<MX;k++){
                ans += pM[i][k] * MT[k][j];
                if(ans > MOD)
                    ans = ans%MOD;
            }
            tmp[i][j]=ans;
        }
    }
    copy();
}

void rpSq(int n) {
    if(m.find(n)!=m.end()){
//        cout<<"got it "<<n<<endl;
        int idx = m.find(n)->second;
        for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) pM[i][j] = pre[idx][i][j];
        return;
    }
    if(n<1)
        return;
    if(n==1){
        for(int i=0;i<MX;i++)
            for(int j=0;j<MX;j++)
                pM[i][j] = MT[i][j];
        return;
    }
    rpSq(n/2);
    square();
    if(n%2){
        multi();
    }
    if(cnt<1000000){
        for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) pre[cnt][i][j] = pM[i][j];
        m[n]=cnt++;
    }
    
}

void copyValTofR(){
    for(int j=0;j<MX;j++){
        fR[j]=val[j];
    }
}

int main(){
    int q,k,i,j;
    inp(q);
    MOD = 1000000007;
    for(i=0;i<MX;i++) for(j=0;j<MX;j++) MT[i][j]=0;
    createMT();
    init();
    while(q--){
        for(i=0;i<MX;i++) for(j=0;j<MX;j++) pM[i][j]=0;
        inp(k);
        if(k==0){
            cout<<"0"<<endl;
            continue;
        }
        if(k==1){
            cout<<"4"<<endl;
            continue;
        }
        rpSq(k-2);
        if(k>2)
            getfRMT();
        else
            copyValTofR();
        cout<<numberOfWays()<<endl;
    }
}
