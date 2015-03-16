#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    string s;
    cin>>a>>b>>c;
    while(a!=0||b!=0||c!=0)
    {
          cin>>s;
          char x[100],y[100],z[100];
          int p[100],q[100],r[100],u1=0,u2=0,u3=0,max=0;
          for(int i=0;i<s.size();i++)
          {
                  if(int(s[i])>=97&&int(s[i])<106)
                  {
                       x[u1]=s[i];
                       p[u1++]=i;
                       if(u1>max)
                       max=u1;
                  }
                  else
                  if(int(s[i])>=106&&int(s[i])<115)
                  {
                       y[u2]=s[i];
                       q[u2++]=i;
                       if(u2>max)
                       max=u2;
                  }
                  else
                  if((int(s[i])>=115&&int(s[i])<123)||int(s[i])==95)
                  {
                       z[u3]=s[i];
                       r[u3++]=i;
                       if(u3>max)
                       max=u3;
                  }
          }
          for(int i=0;i<max;i++)
          {
                  if(i<u1)
                  {
                          if(i-a>=0)
                          s[p[i]]=x[i-a];
                          else
                          s[p[i]]=x[i-a+u1];
                  }
                  if(i<u2)
                  {
                          if(i-b>=0)
                          s[q[i]]=y[i-b];
                          else
                          s[q[i]]=y[i-b+u2];
                  }
                  if(i<u3)
                  {
                          if(i-c>=0)
                          s[r[i]]=z[i-c];
                          else
                          s[r[i]]=z[i-c+u3];
                  }
          }
          cout<<s<<endl;
          cin>>a>>b>>c;
    }
    getch();
    return 0;
}
    
