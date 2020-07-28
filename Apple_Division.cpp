#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
vector<int> ara;
int n;
ll nax = -(1e18), dif, mn = -100, mx = 1e18;
 
void check(int i, ll now) {
    if(i == n) {
        if(now == 0) return;
        if(now > (dif >> 1)) return;
        if(((dif-now) - now) < mx-mn) {
            mn = now;
            mx = (dif-now);
        }
        return;
    }
    check(i+1, now);
    check(i+1, now+ara[i]);
    now -= ara[i];
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
    check(0, 0);
    cout << mx-mn << endl;
 
    return 0;
}