#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector <int> ara(n);
    for (int &i : ara)   cin >> i;
    long long ans = 0;
    
    for (int i = 0; i < n-1; ++i) {
        if(ara[i] > ara[i+1]) {
            ans += (ara[i]-ara[i+1]), ara[i+1] = ara[i];
        }
    }

    cout << ans << endl;

    return 0;
}