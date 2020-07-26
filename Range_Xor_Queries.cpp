#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int auxi[22]; 
template <typename T>
void print(T n) {
    if(n < 0) putchar('-'),n=-n; int i{}; while(n>9) auxi[i++]=n%10,n/=10;
    auxi[i]=n; while(i-->-1) putchar((char)auxi[i+1] + '0'); 
}

template<typename T>
inline void in(T&n) {
    n=0; char ch; while(ch=getchar(), ch <=' '); bool sign(ch== '-');
    if(sign)ch = getchar(); n = ch -'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;  
}

int main()
{
    int t, q, temp;
    in(t), in(q);
 
    vector<ll> ara(t+1);
    ll sum = 0;
    
    for (int i = 1;i <= t; ++i) {
        in(temp);
        ara[i] = (ara[i-1]^temp);
    }
 
    int a, b;
    while(q--) {
        in(a);in(b);
        print(ara[b] ^ ara[a-1]);
        putchar('\n');
    }
   
    return 0;
}