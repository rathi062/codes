#include<iostream>

#include<string.h>
using namespace std;
void c2j(char s[])
{
     int i,q=0,j=0,k=0;
     char r[100];
     for(i=0;i<strlen(s);i++)
     {
                             if(int(s[i])<91)
                             {q=1;
                              break;}
                             if(k==1)
                             {
                                     j++;
                                     r[j]=char(int(s[i])-32);
                                     k=0;
                             }
                             else
                             {
                              if(s[i]=='_')
                              {
                               k=1;
                              }
                              else
                              {
                                  j++;
                                  r[j]=s[i];
                              }
                             }
     }
     if(q==1)
                 {cout<<"Error!\n";
                 q=0;}
                 else
                  cout<<r<<endl;
}

void j2c(char s[])
{     int i,k=0,q=0,j=0;
      char r[100];  
      for(i=0;i<strlen(s);i++)
      {
           if(s[i]=='_')
           {  q=1;
              break;  }
                                 if(int(s[i])<91)
                                 {
                                       j++;
                                       r[j]='_';
                                       j++;
                                       r[j]=char(int(s[i])+32);
                                 }
                                 else
                                 {
                                     j++;
                                     r[j]=s[i];
                                 }
      }
      if(q==1)                      
      {cout<<"Error!\n";
       q=0;  } 
       else
       cout<<r<<endl;       
}
                 
int main()
{ 
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
                  int i=0;
                  for(i=0;i<strlen(s);i++)
                  {
                          if(s[i]=='_')
                          {c2j(s);
                           break;}
                          if(int(s[i])<91)
                          {j2c(s);
                           break;}
                  }            
    }
    return 0;
}
