#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), ans, da(n / 2), db(m / 2), pda((n / 2) + 1), pdb((m / 2) + 1);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n / 2; i ++) da[i] = a[n - i - 1] - a[i];
    for(int i = 0; i < m / 2; i ++) db[i] = b[m - i - 1] - b[i];
    for(int i = 0; i < n / 2; i ++) pda[i + 1] = pda[i] + da[i];
    for(int i = 0; i < m / 2; i ++) pdb[i + 1] = pdb[i] + db[i];

    for(int k = 1;; k++) {
        // choose a point in a as top;
        // a * 2 + (k - a) <= m
        // a + 2 * (k - a) <= n
        int l = max(0, 2 * k - m);
        int r = min(k, n - k);
        if(l > r) break;
        l -= 1;
        while(r > l + 1) {
            int mid = (l + r) >> 1;
            if(da[mid] > db[k - mid - 1]) l = mid;
            else r = mid;
        }
        ans.push_back(pda[r] + pdb[k - r]);
    }
    cout << ans.size() << endl;
    for(ll i : ans) cout << i << ' ';
    cout << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}