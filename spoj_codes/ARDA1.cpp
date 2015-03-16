#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
    int n1=0,n2=0,m1=0,m2=0,c=0;
    cin>>n1>>n2;
    string s1[n1];
    for(int i=0;i<n1;i++)
    cin>>s1[i];
    cin>>m1>>m2;
    string s2[m1];
    for(int i=0;i<m1;i++)
    cin>>s2[i];
    for(int i=0;i<(m1-n1+1);i++)
    {
            for(int j=0;j<(m2-n2+1);j++)
            {
                    if(s1[0][0]==s2[i][j])
                    {
                         int b=0;
                         string s;
                         for(int k=0;k<n1;k++)
                         {
                                 s.assign(s2[i+k],j,n2);
                                 if(s!=s1[k])
                                 {
                                      b=1;
                                      break;
                                 }
                         }
                         if(b==0)
                         {
                             c++;    
                             cout<<"("<<1+i<<","<<j+1<<")"<<endl;
                         }
                    }
            }
    }
    if(c==0)
    cout<<"NO MATCH FOUND...";
    getch();
    return 0;
}
    
