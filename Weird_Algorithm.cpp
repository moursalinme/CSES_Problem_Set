#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;

    while (n) {
        if (n == 1) {
            cout << n << endl;
            break;
        }
        else cout << n << " ";
        
        if (n&1) n *= 3, ++n;
        else    n >>= 1;
    }  

    return 0;
}