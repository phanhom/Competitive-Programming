#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s[n - 2] = 'i';
    cout << s.substr(0, n - 1) << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}