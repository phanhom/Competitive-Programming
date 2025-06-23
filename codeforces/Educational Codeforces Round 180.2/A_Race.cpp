#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(b > c) swap(b, c);

    if(b <= a && a <= c) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}