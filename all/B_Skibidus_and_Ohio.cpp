#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] == s[i + 1]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << n << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}