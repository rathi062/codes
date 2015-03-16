#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
    string s="mohit rathi",a[2];
    a[0].assign(s,0,5);
    cout<<a[0]<<endl;
 //   size_t  comp = s.compare(a[0],1,5);
//    if(comp==0)
  //  cout<<a[0]<<endl;
    a[1].assign(s,6,5);
    cout<<a[1];
    getch();
    return 0;
}
    
