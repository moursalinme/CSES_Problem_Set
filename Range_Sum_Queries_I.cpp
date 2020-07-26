#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() 
{
    int t, q, temp;
    cin >> t >> q; 
    vector<ll> ara(t+1);
    ll sum = 0;
    
    for (int i = 1;i <= t; ++i) {
        cin >> temp;
        ara[i] += temp+ara[i-1];
    }
    int a, b;
 
    while(q--) {
        cin >> a >> b;
        cout << (ara[b] - ara[a-1]) << endl;
    }
 
    return 0;
}
