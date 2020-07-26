#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int auxi[22]; 
template <typename T>
void print(T n) {
    if(n < 0) putchar('-'),n=-n; int i{}; while(n>9) auxi[i++]=n%10,n/=10;
    auxi[i]=n; while(i-->-1) putchar((char)auxi[i+1] + '0'); 
}
 
template <typename T>
void in(T &n) { 
    n=0; char ch; while(ch=getchar(),ch<=' '); bool sign(ch=='-'); if(sign)ch=getchar(); n=ch-'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;  
}

const int nax = 2*(1e5+7);
vector<int> ara(nax);
vector<pair<ll, ll>> tree(nax*3);

void build (int cur, int lo, int hi) {
    if(lo == hi) {
        tree[cur] = {(ll)ara[lo], 0};
        return;
    }
    int mid = (lo+hi)>>1;
    build(cur<<1, lo, mid);
    build((cur<<1)+1, mid+1, hi);
}

void update (int cur, int lo, int hi, int i, int j, int val) {
    if (lo > j || hi < i) {
        return;
    }
    if (lo >= i && hi <= j) {
        tree[cur].second += val;
        return;
    }
    int mid = (lo+hi)>>1;
    update (cur<<1, lo, mid, i, j, val);
    update ((cur<<1)+1, mid+1, hi, i, j, val);
}

ll cal_value;

void qury (int cur, int lo, int hi, int i, int j) {
    if (lo > j || hi < i) {
        return;
    }
    if(lo >= i && hi <= j) {
        tree[cur].first += tree[cur].second;
        cal_value = tree[cur].first;
        tree[cur].second = 0;
        return;
    }
    if(tree[cur].second != 0) {
        tree[cur<<1].second += tree[cur].second;
        tree[(cur<<1)+1].second += tree[cur].second;
        tree[cur].first += tree[cur].second;
        tree[cur].second = 0;
    }
    int mid = (lo+hi)>>1;
    qury (cur<<1, lo, mid, i, j);
    qury ((cur<<1)+1, mid+1, hi, i, j);
}
 
int main() 
{
    int n, q, lo, hi, qt = 1, val;
    in(n); in(q);

    for (int i = 0; i < n; ++i) {
        in(ara[i]);
    }
    build(1, 0, n-1);

    while(q--) {
        in(qt);
        if(qt == 1) {
            in(lo); in(hi); in(val);
            update (1, 0, n-1, lo-1, hi-1, val);
        } 
        else {
            in(lo);
            qury (1, 0, n-1, lo-1, lo-1);
            print(cal_value);
            putchar('\n');
        }
    }
    return 0;
}