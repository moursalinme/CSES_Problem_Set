#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int auxi[22]; 
template<typename T>
void print(T n) {
    if(n < 0) putchar('-'),n=-n;int i{};while(n>9)auxi[i++]=n%10,n/=10;
    auxi[i]=n;while(i-->-1) putchar((char)auxi[i+1] + '0'); 
}
 
template<typename T>
void in(T &n) { 
    n=0;char ch;while(ch=getchar(),ch<=' ');bool sign(ch=='-');if(sign)ch=getchar();n=ch-'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;  
}
 
const int Mx = 1e9+7;
 
long long bpow(long long x, long long y, int M) {
    long long ret = 1;
    while (y) {
        if (y&1) ret = (ret * x) % M;
        x = (x*x) % M;
        y >>= 1; 
    }
    return ret % M;
}
 

int main()
{
    int t;
    long long a, b, c;
    in(t);
 
    while (t--) {
        in(a); in(b); in(c);
        long long x = bpow(b, c, Mx-1);
        print(bpow(a, x, Mx));
        putchar('\n');
    }
   
    return 0;
}