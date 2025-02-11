#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0 ; i < s.size(); i ++) {
        if(s[i] == '1') ans ++;
    }
    cout << ans << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}