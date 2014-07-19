#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{    int m,n,i,j;
    cout<<"\nenter the order of the matrix";
    cin>>m>>n;
    int a[m][n],b[m][n],c[m][n];
    cout<<"enter elements of first metrix ";
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        cin>>a[i][j];
    cout<<"enter elements of second metrix ";
    for(i=0;i<m;i++)
       for(j=0;j<n;j++)
          cin>>b[i][j];
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
          c[i][j]=a[i][j]+b[i][j];
       }
    }
        cout<<"sum of metrixes is : ";
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      { 
        cout<<c[i][j]<<" ";
      }
      cout<<endl;
    }
    getch();
    return 0;
}
