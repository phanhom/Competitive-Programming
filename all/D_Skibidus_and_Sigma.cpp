#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    ll sum = 0;
    ll n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    vector<ll> row_sum(n);
    for(ll i = 0; i < n; i ++) {
        for(ll j = 0; j < m; j ++) {
            cin >> a[i][j];
            sum += (m - j) * a[i][j];
            row_sum[i] += (ll) a[i][j];
        }
    }
    sort(row_sum.begin(), row_sum.end());
    // for(auto k : row_sum) cout << k << '-';
    for(ll i = 0; i < n; i ++) {
        ll tmp = i * m * row_sum[i];
        // cout << tmp << '-';
        sum += tmp;
    }
    cout << sum << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}