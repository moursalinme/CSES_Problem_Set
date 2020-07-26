#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n, temp;
    cin >> n;
    set <int> ms;
 
    while (n--) {
        cin >> temp;
        ms.insert(temp);
    }
    cout << ms.size() << endl;
    
    return 0;
}
