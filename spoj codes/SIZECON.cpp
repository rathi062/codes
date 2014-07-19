# include <iostream>
# include <conio.h>
using namespace std;
int main()
 {
  int i,t,a,sum=0;
  cin >>t;
  for(i=0;i<t;++i)
   {
    cin >>a;
    if(a>0)
     sum+=a;
   }
  cout <<sum;   
  getch();
  return 0;
 }
