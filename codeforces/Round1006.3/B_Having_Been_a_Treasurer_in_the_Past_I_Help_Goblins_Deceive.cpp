#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    ll n, cnt0 = 0, cnt1 = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '_') cnt0 ++;
        else cnt1 ++;
    }
    ll res = (ll) (cnt1 / 2ll) * (cnt1 - (cnt1 / 2ll)) * cnt0;
    cout << res << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}