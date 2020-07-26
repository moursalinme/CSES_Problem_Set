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
 
void strp(string s) {
    for (auto i: s) {
        putchar(i);
    }
    putchar('\n');
}
 
void solve() {
    int n, sum = 0, temp;
    in(n);

    while(n--) {
        in(temp);
        sum ^= temp;
    }
    if(sum) strp((string)"first") ;
    else    strp((string)"second");
}
 
int main()
{
    int t;
    in(t);
 
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}