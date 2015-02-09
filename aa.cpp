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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


class BracketExpressions {
public:
	string ifPossible(string expression) {
		bool dp[51][51]={0};
		int l=expression.size();
		if(l%2)
            return "impossible";
		bool check[51][51]={0};
		for(int i=2;i<=l;i+=2)
		{
			cout<<"\nl = "<<i;
			for(int j=0;j<l;j++)
			{
				int k=j+i-1,st=j,ed=k,b=0;
				
				while(st<ed && ed<l)
				{
					cout<<endl<<expression[st]<<" "<<expression[ed];
					if(expression[st]=='X' || expression[ed]=='X' || expression[st]==expression[ed])
					{
						st++;
						ed--;
					}
					else
                        if(expression[st]!=expression[ed])
                        {
                            check[j][k]=0;
                            b=1;
                            break;
                        }
					
				}
				cout<<"\nb = "<<b;
				if(b==0)
                    check[j][k]=1;
			}
		}
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				cout<<check[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l-1;j++)
			{
				if(check[i][j]&&check[j+1][l-1])
                    return "possible";
			}
		}
		return "impossible";
	}
};


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
