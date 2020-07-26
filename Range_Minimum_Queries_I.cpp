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
 
const int mx = (1e5+7) * 2; 
int inf = 1e9;
int tree[3 * mx];
int ara[mx];
 
void maketree(int cur, int i, int j) {
    if(i == j) {
        tree[cur] = ara[i];
        return;
    }

    int mid  = ((i +  j) >> 1);
    maketree((cur<<1), i, mid);
    maketree((cur<<1)+1, mid+ 1, j);
    tree[cur] = min( tree[(cur<<1)] , tree[(cur<<1)+1]);
    return;
}


ll sum(int cur, int low, int high, int i, int j) {
    if(i > high || j < low) {
        return inf;
    }
    if(low >= i && high <= j) {
        return tree[cur];
    }

    int mid = ((low + high) >> 1);
    ll sum1, sum2;
    sum1 = sum((cur << 1), low, mid, i, j);
    sum2 = sum((cur << 1)+1, mid+1, high, i, j);
    return min(sum1 , sum2);
}

int main()
{
    int sz, quri;
    in(sz); in(quri);
    
    for(int i = 1; i <= sz; ++i) {
        in(ara[i]);
    }
    maketree(1,1,sz);
 
    while(quri--) {
        int l, h;
        in(l), in(h);
        print(sum(1,1, sz,l, h));
        putchar('\n');
    }
    return 0;
}