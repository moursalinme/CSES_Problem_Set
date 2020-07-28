#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    string s;
    cin >> s;
    int ara[27]{};
 
    for (auto i : s) {
        ara[i - 'A']++;
    } 
    int ss = s.size();
    vector<char> ans(ss+1);
    int i = 1, j = ss;
 
    for (int k = 0; k < 26; ++k) {
        if(ara[k]) {
            int add = ara[k]/2;
            ara[k] -= (add*2);
 
            while(add--) {
                ans[i++] = 'A'+k;
                ans[j--] = 'A'+k;
            }
        }
    }
 
    if((j-i == 0) || (j-i == -1)) {
        for (int k = 0; k < 26; ++k) {
            if(ara[k] > 0) {
                ans[i++] = 'A'+k;
                break;
            }
        }
 
        for (int k = 1; k <= ss; ++k) 
            cout << ans[k];
        cout << endl;
    }
    else cout << "NO SOLUTION" << endl;
 
    return 0;
}