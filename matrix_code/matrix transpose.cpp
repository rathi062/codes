#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{   int m,n,i,j;
cout<<"\nenter rows and columns";
    cin>>m>>n;
    int a[m][n],b[m][n];
    for(i=0;i<m;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    cin>>a[i][j];
                                    }
                                    }
                                    for(i=0;i<n;i++)
                                    {
                                                    for(j=0;j<m;j++)
                                                    {
                                                                    b[i][j]=a[j][i];
                                                                    }
                                                                    }for(i=0;i<n;i++)
                                                                    {
                                                                                     for(j=0;j<m;j++)
                                                                                     {
                                                                                                     cout<<b[i][j]<<" ";
                                                                                                     }
                                                                                                     cout<<endl;
                                                                                                     }
                                    getch();
                                    return 0;
                                    }
    
