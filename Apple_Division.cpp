#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
vector<int> ara, col;
int n;
ll nax = -(1e18), dif, mn = -100, mx = 1e18;
 
void check(int i) {
    if(i == n) {
        if(col.empty()) return;
        ll now  = 0;
        for (auto i: col) {
            now += i;
        }
        if(now > (dif >> 1)) return;
        if(((dif-now) - now) < mx-mn) {
            mn = now;
            mx = (dif-now);
        }
        return;
    }
    check(i+1);
    col.push_back(ara[i]);
    check(i+1);
    col.pop_back();
} 
 
int main() 
{   
    cin >> n;
    ara.resize(n);
 
    for (int& i: ara)   {
        cin >> i;
        dif += i;
    }
    if(n==1) {
        cout<< ara[0]<<endl;
        return 0;
    }
    check(0);
    cout << mx-mn << endl;
 
    return 0;
}