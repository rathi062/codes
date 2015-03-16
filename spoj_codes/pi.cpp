#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
    fstream file,file1;
    file.open("pi.txt",ios::in);
    file1.open("pi2.txt",ios::out|ios::app);
    while(!file.eof())
    {
                      string s;
                      file>>s;
                      for(int i=0;i<s.size();i++)
                      {
                              if(s[i]==':')
                              break;
                               file1<<s[i];
                      }
    }
    file.close();
    file1.close();
    getch();
    return 0;
}
                      
