#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int mx = 1, sz = s.size()-1, cnt = 1;

    for (int i = 0; i < sz; ++i) {
        if(s[i] == s[i+1]) ++cnt;
        else {
            mx = max(cnt, mx);
            cnt = 1;
        }
    }
    cout << max(cnt, mx) << endl;

    return 0;
}