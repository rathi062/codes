#include<iostream>
using namespace std;
main()
{
int n,t;
cin>>t;
while(t--){
long double a,s=0;
cin>>n;
while(n){
cin>>a;
n--;
s+=a<0?a:0;
if(!n)break;
cin>>a;
n--;
s+=a>0?a:0;}
if(s<0)cout<<"Every Girl Lies!\n";
else cout<<"Some Mirrors Lie!\n";
}
}
 

