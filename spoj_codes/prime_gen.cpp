    #include <stdio.h>
    #include<conio.h>
    #include <string.h>
    #include <math.h>
    #include <bitset>
    using namespace std;
    bitset<50003> A;
    unsigned int P[3401];
    char buffer[8192];
    int ind = 0;
    inline void flush()
    {
    fputs(buffer,stdout);
    ind = 0;
    }
    static char sbuf[12] = {0,0,0,0,0,0,0,0,0,0,'\n',0};
    inline char * itoa(unsigned int _a, unsigned int & _len)
    {
    char *pos = sbuf + 10;
    do
    {
    *--pos = '0' + (_a%10);
    _a/=10;
    } while(_a);
    _len = sbuf+11-pos;
    return pos;
    }
    inline void bufwrite(unsigned int _a)
    {
    char *s = 0;
    unsigned int len;
    s = itoa(_a, len);
    strcpy(buffer+ind, s);
    ind+=len;
    if(ind>8000)
    flush();
    }
    inline bool print_from_array(unsigned int _m, unsigned int _n)
    {
    if(_m > 31607) return true;
    if(_n < 2) return false;
    if(_m <= 2) {bufwrite(2); _m=2;}
    if(_n > 2)
    {
    unsigned int i = 0;
    for(i = 0; i < 3400; i++)
    {
    if((P[i] >= _m) && (P[i] <= _n))
    bufwrite(P[i]);
    else if(P[i] >= _n) return false;
    }
    }
    else
    return false;
    return true;
    }
    void precalc()
    {
    unsigned int pp = 3, i = 0, j;
    for(; pp <= 178; pp+=2, i++)
    if(!A[i])
    for(j = i+pp; j <= 15802; j+=pp)
    A[j] = true; // not a prime
    for(i = 0, j = 0; i <= 15802; i++)
    if(!A[i]) P[j++] = (i<<1) + 3;
    P[3400] = 100000;
    A.reset();
    }
    void print_primes(unsigned int _m, unsigned int _n)
    {
    if(!print_from_array(_m, _n)) {flush();return;}
    if(_m<=31607) _m = 31627;
    unsigned int max = (unsigned int) sqrt((double)_n) +1, c, p=3, i=0, j, k;
    for(; max >= P[i]; p = P[++i])
    {
    c = (unsigned int) ceil((double)_m/p)*p;
    if(!(c&1)) c+=p;
    for(j = c, k = (c-_m)/2; j <= _n; j += 2*p, k += p)
    A[k] = true;
    }
    p = _m&1 ? _m : _m+1;
    for(i = 0; p <= _n; p+=2, i++)
    if(!A[i]) bufwrite(p);
    flush();
    A.reset();
    }
    int main()
    {
    unsigned int t=0, m=0, n=0;
    scanf("%u", &t);
    precalc();
    while(t--)
    {
    scanf("%u %u", &m, &n);
    print_primes(m, n);
    puts("");
    }
    getch();
    return 0;
    } 
