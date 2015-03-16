#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string s;
    while(!getline(cin,s).eof())
    {
          if(s[0]=='*')
          break;
           char ch;
           ch=toupper(s[0]);
           //cout<<ch;
           int r=0;
           for(int i=0;i<s.size();i++)
           {
                   if(s[i]==' ')
                   {
                              char c;
                              c=toupper(s[i+1]);
                              if(c!=ch)
                              {
                                       r=1;
                                       cout<<"N\n";
                                       break;
                              }
                   }
           }
           if(r==0)
           cout<<"Y\n";
            
    }
    getch();
    return 0;
}
                              
