#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n;
    string haab[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    string tz[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    for(int i=0;i<n;i++)
    {
            int d,y=9,t=0,j=0;
            string s,v;
            cin>>d>>v>>s>>y;
            //cout<<d<<v<<s<<y;
            for( j=0;j<19;j++)
            {
                    if(s==haab[j])
                    break;
            }
            t=(y*365)+(j*20)+d;
            //cout<<endl<<t<<endl;
            cout<<endl<<(t%13)+1<<" "<<tz[(t%20)]<<" "<<(t/260);
    }
    getch();
    return 0;
}
