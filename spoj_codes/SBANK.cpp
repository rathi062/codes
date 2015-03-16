#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void quick(string s[],int low ,int high )
{
     int k,c,i;
     string sv;
     k=high-1;
     i=low;
     if(high>low)
     {
        while(i!=k)
        {
           int c=0;
           c=strcmp(s[i].c_str(),s[k].c_str());
           if(c==1)
           {
              sv=s[i];
              s[i]=s[k-1];
              s[k-1]=s[k];
              s[k]=sv;
              k=(k-1);
           }
           else 
           {  i=i+1;  }
        }
        quick(s,low,k);
        quick(s,(k+1),high);
     }
}
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n;
            cin>>n;
            string s[n];
            for(int j=0;j<n;j++)
            {
                    getline(cin,s[i]);
            }
            for(int j=0;j<n;j++)
            cout<<s[i]<<endl;
            cout<<endl;
            quick(s,0,n);
            for(int j=0;j<n;j++)
            cout<<s[i]<<endl;
            int i=0;
           /* while(i<n-1)
           {      cout<<s[i]<<" ";
                  int l=1,t=1;
                   while(l==1)
                   {
                     int a=strcmp(s[i].c_str(),s[i+1].c_str());
                     if(a==0)
                     {
                             if(i!=n-1) 
                             i++;
                             else
                             l=0;   
                             t++;
                     }
                     else
                     {
                         l=0;
                         i++;
                     }
                     
                   }cout<<t<<endl;
           }*/
           /*int c=1;
           for(i=0;i<n;i++)
           {
                           int a=0;
                if(i==n-1)
                cout<<s[i]<<" "<<c<<endl;
                else
                {
                    a=strcmp(s[i].c_str(),s[i+1].c_str());
                    if(a==0)
                    c++;
                    else
                    {
                        cout<<s[i]<<" "<<c<<endl;
                        c=1;
                    }
                }
           }*/
    }
    getch();
    return 0;
}
