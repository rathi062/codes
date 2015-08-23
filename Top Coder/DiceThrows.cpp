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

#define PB push_back
#define LL long long
#define pii pair<int, int>
#define MP(a,b) make_pair(a,b)
#define CLR(a) memset(a,0,sizeof(a))
#define MX 100001

//#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
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

int a,b,dice1[6],dice2[6],mx1,mx2;
double freq1[201][20001], freq2[201][20001];
double s1,s2,sum2[20001];

void computeAns(){
    sum2[0]=0.0;
    for(int i=1;i<=mx2*b;i++){
        sum2[i] = sum2[i-1] + freq2[b][i];
    }
    s2 = sum2[mx2*b];
    double result = 0.0;
    for(int i=1;i<=mx1*a;i++){
        result += freq1[a][i]*sum2[i-1];
    }
    cout<<result<<endl;
}

void init(){
    for(int i=0;i<6;i++){
        freq1[1][dice1[i]] = 0.0;
        freq2[1][dice2[i]] = 0.0;
    }
    for(int i=0;i<6;i++){
        freq1[1][dice1[i]] += (1*1.0/6);
        freq2[1][dice2[i]] += (1*1.0/6);
    }
}

void computeFreq1(){
    
    for(int i=1;i<a;i++){
        for(int j=i; j <= (mx1*i); j++){
            double toAdd = (freq1[i][j]/6)*1.0;
            for(int k=0;k<6;k++)
                freq1[i+1][j + dice1[k]] += toAdd;
        }
    }
}

void computeFreq2(){
    
    for(int i=1;i<b;i++){
        for(int j=i; j <= (mx2*i); j++){
            double toAdd = (freq2[i][j]/6)*1.0;
            for(int k=0;k<6;k++)
                freq2[i+1][j + dice2[k]] += toAdd;
            }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        CLR(freq1);
        CLR(freq2);
        CLR(sum2);
        mx1 = mx2 = 0;
        cin>>a;
        for(int i=0;i<6;i++) {
            cin>>dice1[i];
            if(dice1[i]>mx1)
                mx1 = dice1[i];
        }
        cin>>b;
        for(int i=0;i<6;i++) {
            cin>>dice2[i];
            if(dice2[i]>mx2)
                mx2 = dice2[i];
        }
        init();
        computeFreq1();
        computeFreq2();
        computeAns();
        
    }
}