#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string s;
    while(!getline(cin,s).eof())
    {
         int o=0,c=0,cd;
         for(int i=0;i<s.size();i++)
         {
                 cd=int(s[i]);
                 if(o==0)
                 {
                      if((cd>64&&cd<91)||(cd>96&&cd<123))
                      {
                           o=1;
                           c++;
                      }
                 }
                 else
                 {
                     if(cd<65||(cd>90&&cd<97)||cd>122)
                     o=0;
                 }
         }
         cout<<c<<endl;
                         
    }
    getch();
    return 0;
}
