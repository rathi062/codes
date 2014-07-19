#include<iostream>
using namespace std;

int main(){
  int n,sum=0, k;
  cout<<"enter value of  n";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    sum=sum+i; 
    
	if(sum == 2)	
	{
		continue;
       
	}
    else
    {
	for(count=2; count<sum; count++)	
	{
		if(sum%count == 0)	
		{
			check = 1;
		}
	}
 
	if(check == 0)	
	{
	continue;
	}
	else
	{
		cout<<"The number you entered is not a prime number."<<endl;
        i=k;
        
     }
        
   }
 }   
  for(int j=1;j<=k;j++)
  cout<<j;
   int u;
   cin>>u;
  return 0;
}
