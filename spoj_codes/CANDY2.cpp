#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
     int n=0,k=0;
     cin>>n;
     int a[n],b[n],c[n];
     int ma=0,mb=0,mc=0,ina=-1,inb=-1,inc=-1;
     for(int i=0;i<n;i++)
     {
             cin>>a[i]>>b[i]>>c[i];
             if(a[i]>ma)
             {ma=a[i];
              ina=i;}
             if(b[i]>mb)
             {mb=b[i];
              inb=i;}
             if(c[i]>mc)
             {mc=c[i];
             inc=i;}
     }
     //cout<<"\nina = "<<ina<<"\ninb = "<<inb<<"\ninc = "<<inc;
     while(ina==inb||inb==inc||ina==inc)
     {
         // cin>>k;
         //cout<<"\nina = "<<ina<<"\ninb = "<<inb<<"\ninc = "<<inc;
         if(ina==inb)
         {
           //          cout<<"\ncase 1";
              int nwa=0,nwb=0;
              ma=0,mb=0;
              for(int i=0;i<n;i++)
              {
                  if(a[i]<=a[ina]&&a[i]>=ma&&ina!=i)
                  { ma=a[i];
                    nwa=i;}
                  if(b[i]<=b[inb]&&b[i]>=mb&&inb!=i)
                  { mb=b[i];
                    nwb=i;}  
              }
              if((a[ina]+b[nwb])<(a[nwa]+b[inb]))
              ina=nwa;
              else
              inb=nwb;
            //  cout<<"\nina = "<<ina<<"\ninb = "<<inb<<"\ninc = "<<inc;
         }
         if(ina==inc)
         {
              //       cout<<"\ncase 2";
              int nwa=0,nwc=0;
              ma=0,mc=0;
              for(int i=0;i<n;i++)
              {
                  if(a[i]<=a[ina]&&a[i]>=ma&&ina!=i)
                  { ma=a[i];
                    nwa=i;}
                  if(c[i]<=c[inc]&&c[i]>=mc&&inc!=i)
                  { mc=c[i];
                    nwc=i;}  
              }
              if((a[ina]+c[nwc])<(a[nwa]+c[inc]))
              ina=nwa;
              else
              inc=nwc;
              //cout<<"\nina = "<<ina<<"\ninb = "<<inb<<"\ninc = "<<inc;
         }
         if(inc==inb)
         {
                //     cout<<"\ncase 3";
              int nwc=0,nwb=0;
              mc=0,mb=0;
              for(int i=0;i<n;i++)
              {
                  if(c[i]<=c[inc]&&c[i]>=mc&&inc!=i)
                  { mc=c[i];
                    nwc=i;}
                  if(b[i]<=b[inb]&&b[i]>=mb&&inb!=i)
                  { mb=b[i];
                    nwb=i;}  
              }
              //cout<<"\nnwb = "<<nwb<<"\nnwc = "<<nwc;
              if((c[inc]+b[nwb])<(c[nwc]+b[inb]))
              inc=nwc;
              else
              inb=nwb;
              //cout<<"\nina = "<<ina<<"\ninb = "<<inb<<"\ninc = "<<inc;
         }
         
     }
     cout<<ina<<endl<<inb<<endl<<inc;
     getch();
     return 0;
}
                  
