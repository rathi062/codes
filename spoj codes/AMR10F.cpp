# include <iostream.h>
# include <conio.h>
using namespace std;

int main()
  {
   int i,n,a,d,t;
   cin >>t;
   for(i=0;i<t;++i)
    {
     cin >>n>>a>>d;
     cout<<(n*((2*a)+(n-1)*d))/2;
    }
   getch();
   return 0;
}
