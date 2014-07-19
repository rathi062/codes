#include<iostream>
#include<vector>
using namespace std;
int main()
{
        long long int n,sum=0,i,j;
         vector<long long int> a;       
        int t;
        a.push_back(sum);
                 scanf("%d",&t);
        for(i=1;i<=1000000;i++)
          {  
                    sum=(sum+i*i*i)%1000000003;
                           a.push_back((a[i-1]+sum)%1000000003);
                 // printf("sum %lld a[%lld] %lld\n",sum,i,a[i]);
                           }
                          
        while(t--)
        {  
       scanf("%llu",&n);   
              printf("%lld\n",a[n]);
       
    }
           
           }
