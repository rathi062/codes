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

using namespace std;

int no,m;

long long fibonacci(int n)
{
    long long fib[2][2]= {{0,no},{1,2}},ret[2][2]= {{0,no},{1,2}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            for(i=0; i<2; i++) for(j=0; j<2; j++) tmp[i][j]=0;
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j]);
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        for(i=0; i<2; i++) for(j=0; j<2; j++) tmp[i][j]=0;
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
            tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j]);
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][0]);
}

int main(){
    cin>>no>>m;
    if(m<=1)
        cout<<"0\n";
    else
        cout<<fibonacci(m-1)<<endl;
}