#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
          string s[10];
          int a[10],max=0;
          
          for(int j=0;j<10;j++)
          {
                  cin>>s[j]>>a[j];
                  if(max<a[j])
                  max=a[j];
          }
          cout<<"Case #:"<<i+1<<"\n";
          for(int j=0;j<10;j++)
          {
                  if(a[j]==max)
                  cout<<s[j]<<endl;
          }
    }
    getch();
    return 0;
}
