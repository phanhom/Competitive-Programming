#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    vector<ll> a(3);
    ll x, ans = 0;
    cin >> x;
    while(a[0] < x) {
        a[0] = a[1] * 2ll + 1ll;
        sort(a.begin(), a.end());
        ans ++;
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