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

    vector<string> a;
    int cardi[21];
    void init(){
        for(int i=0;i<a.size();i++)
        {
            int result =0;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='Y')
                    result++;
            }
            cardi[i]=result;
        }
    }
    int countPair(vector<string> a){
        cout<<"in getresult";
        init();
        int cnt=0;
        for(int i=0;i<a.size();i++){
            int val =  cardi[i];
            for(int j=i+1;j<a.size();i++){
                if(cardi[j]==0){
                    if(val>1)
                        cnt++;
                }
                if(cardi[j]==1){
                    if(val==2){
                        if(a[i][j]=='N')
                            cnt++;
                    }
                    if(val>2)
                        cnt++;
                }
                if(cardi[j]==2){
                    if(val==0)
                        cnt++;
                    if(val==1){
                        if(a[i][j]=='N')
                            cnt++;
                    }
                    if(val>=2)
                        cnt++;
                }
                if(cardi[j]>2){
                    cnt++;
                }
            }
        }
        return cnt;
    }

int main(){
    string arr[] = {"NYNYNNYYNN","YNNNYNYYNN","NNNNYNNNYN","YNNNYYNNNN","NYYYNNNNYN","NNNYNNNNYN","YYNNNNNNNN","YYNNNNNNYN","NNYNYYNYNY","NNNNNNNNYN"};
    vector<string> aaa (arr, arr + sizeof(arr)/sizeof(string));
    cout<<"input end  size(a) = "<<aaa[0];
    int result = countPair(aaa);
    cout<<result;
}
