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


class FoxAndSouvenirTheNext {
public:
    
    long getSum(vector <int> value){
        long result=0;
        for(int i=0;value.size();i++)
            result += value[i];
        return result;
    }
    
    bool fun(vector<int> value, int toSelect, int remaining, int index){
        if(index >= value.size() || remaining < 0)
            return false;
        if(toSelect==0)
        {
            if(remaining==0)
                return true;
            else
                return false;
        }
        return  ( fun(value,toSelect-1,remaining-value[index],index+1) || fun(value, toSelect, remaining, index+1) );
        
    }
    
    string ableToSplit(vector <int> value) {
        string result = "Impossible";
        long sum = getSum(value);
        if(sum%2 || value.size()%2)
            return result;
        bool isPossible = fun(value,value.size()/2,sum/2,0);
        if(isPossible)
            result = "Possible";
        return result;
    }
};
