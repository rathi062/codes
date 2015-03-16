#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MX 100
using namespace std;

long long a[MX][MX];
long long result[MX][MX];
long long tmp[MX][MX];
int sz,md;


void print(){
    cout<<result[0][0]<<" ";
    cout<<result[0][1]<<endl;
    cout<<result[1][0]<<" ";
    cout<<result[1][1]<<endl;
}
void copy(){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            result[i][j]=tmp[i][j];
        }
    }
}
void square(){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            long long ans=0;
            for(int k=0;k<sz;k++){
                ans+=result[i][k]*result[k][j];
                if(ans > md)
                    ans = ans%md;
            }
            tmp[i][j]=ans;
        }
    }
    copy();
}

void multi(){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            long long ans=0;
            for(int k=0;k<sz;k++){
                ans+=result[i][k]*a[k][j];
                if(ans > md)
                    ans = ans%md;
            }
            tmp[i][j]=ans;
        }
    }
    copy();
}

void repeatedSquering(int n) {
    if(n==1){
        result[0][0]=1;
        result[0][1]=1;
        result[1][0]=1;
        result[1][1]=0;
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

void init(){
    sz=2;
    a[0][0]=1;
    a[0][1]=1;
    a[1][0]=1;
    a[1][1]=0;
}

int main(){
    init();
    md=1000000009;
    int n;
    cin>>n;
    repeatedSquering(n);
    print();
}