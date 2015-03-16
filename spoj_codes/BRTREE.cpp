#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=1,k=1,i=0;
    long long sum=0;
    
    while(n!=0&&k!=0)
    {
        cin>>n>>k;
        sum=0;
        for(i=0;i<n-1;i++)
        {
            if(sum<1234567890)
            sum+=(n-(i+1))*pow(k,i);
        }
        cout<<sum<<endl;
        
    }
    getch();
    return 0;
}
                        
    
