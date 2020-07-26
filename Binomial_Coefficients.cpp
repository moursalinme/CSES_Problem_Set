#include <bits/stdc++.h>

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
 
vector<ll> fact(1000007);
const int M = 1e9+7;
 
ll minverse(ll a, ll b) {
    ll ret = 1;
    for (; b; b>>=1) {
        if (b&1) 
            ret = (ret * a) % M;
        a = (a*a) % M;
    }
    return ret % M;
}
 
ll ncr(int n, int r) {
    ll up, down;
    up = fact[n];
    down = ((fact[r]) * (fact[n-r]))%M;
    down = minverse(down, M-2);
    up = (up*down)%M;
    return up;
}
 
void solve() {
    ll n, r;
    in(n); in(r);
    print(ncr(n,r));
    putchar('\n');
}
 
int main()
{
    fact[0] = 1;
    
    for (int i = 1; i < 1000001; ++i) {
        fact[i] = ((ll)fact[i-1]*i) % M;
    }
    int t;
    in(t);
 
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}