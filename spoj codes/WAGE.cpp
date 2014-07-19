#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int r=0,c=0,n=0;
            cin>>r>>c>>n;
            char a[r][c],b[r][c];
            for(int j=0;j<r;j++)
            {
                    for(int k=0;k<c;k++)
                    {
                            cin>>a[j][k];
                            b[j][k]=a[j][k];
                    }
            }
            for(int j=0;j<n;j++)
            {
                    //if(j%2==0)
                    //{
                              for(int l=0;l<r;l++)
                             {
                                      for(int k=0;k<c;k++)
                                      {
                                            if(a[l][k]=='W')
                                            {  
                                                if(k>0&&a[l][k-1]=='G')
                                                b[l][k]='G';
                                                if(k<(c-1)&&a[l][k+1]=='G')
                                                b[l][k]='G';
                                                if(l>0&&a[l-1][k]=='G')
                                                b[l][k]='G';
                                                if(l<(r-1)&&a[l+1][k]=='G')
                                                b[l][k]='G';
                                            }
                                            
                                            if(a[l][k]=='G')
                                            {  
                                                if(k>0&&a[l][k-1]=='A')
                                                b[l][k]='A';
                                                if(k<(c-1)&&a[l][k+1]=='A')
                                                b[l][k]='A';
                                                if(l>0&&a[l-1][k]=='A')
                                                b[l][k]='A';
                                                if(l<(r-1)&&a[l+1][k]=='A')
                                                b[l][k]='A';
                                            }
                                            
                                            if(a[l][k]=='A')
                                            {  
                                                if(k>0&&a[l][k-1]=='W')
                                                b[l][k]='W';
                                                if(k<(c-1)&&a[l][k+1]=='W')
                                                b[l][k]='W';
                                                if(l>0&&a[l-1][k]=='W')
                                                b[l][k]='W';
                                                if(l<(r-1)&&a[l+1][k]=='W')
                                                b[l][k]='W';
                                            }
                                      }
                             }
                              
                    for(int j=0;j<r;j++)
                    {
                            for(int k=0;k<c;k++)
                            {
                                    a[j][k]=b[j][k];
                            }
                    }
            }
            for(int j=0;j<r;j++)
            {
                    for(int k=0;k<c;k++)
                    {
                            cout<<a[j][k];
                    }
                    cout<<endl;
            }
    }
    getch();
    return 0;
}
