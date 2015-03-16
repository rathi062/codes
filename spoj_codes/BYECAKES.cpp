#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int e,f,s,m,ed,fd,sd,md;
    cin>>e>>f>>s>>m>>ed>>fd>>sd>>md;
    while(e!=-1)
    {
                int d1=0,d2=0,d3=0,d4=0,r1=0,r2=0,r3=0,r4=0,max=0;
                if(ed==0)
                d1=0;
                else
                {
                if(e%ed==0)
                d1=e/ed;
                else
                d1=(e/ed)+1;
                }
                if(max<d1)
                max=d1;
                if(fd==0)
                d2=0;
                else
                {
                if(f%fd==0)
                d2=f/fd;
                else
                d2=(f/fd)+1;
                }
                if(max<d2)
                max=d2;
                if(sd==0)
                d3=0;
                else
                {
                if(s%sd==0)
                d3=s/sd;
                else
                d3=(s/sd)+1;
                }
                if(max<d3)
                max=d3;
                if(md==0)
                d4=0;
                else
                {
                if(m%md==0)
                d4=m/md;
                else
                d4=(m/md)+1;
                }
                if(max<d4)
                max=d4;
                r1=(ed*max)-e;
                r2=(fd*max)-f;
                r3=(sd*max)-s;
                r4=(md*max)-m;
                cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
                cin>>e>>f>>s>>m>>ed>>fd>>sd>>md;
    }
    getch();
    return 0;
}
