#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long sum = 0, n, temp;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        cin >> temp;
        sum += temp;
    }
    cout << (n*(n+1))/2 - sum << endl;

    return 0;
}