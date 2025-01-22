#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), cnt(m);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    int rate = a[0];
    sort(a.begin(), a.end());
    // sort(b.begin(), b.end());

    for(int i = 0; i < m; i ++) {
        if(b[i] <= rate) cnt[i] = 0;
        else {
            auto it = lower_bound(a.begin(), a.end(), b[i]);
            cnt[i] = a.end() - it;
        }
    }
    sort(cnt.begin(), cnt.end());
    // return;

    for(int k = 1; k <= m; k ++) {
        // cout << cnt[k - 1] << ' ';
        long long ans = 0;
        for(int i = 0; i < m; i += k) {
            if(i + k > m) continue;
            // continue;
            int r = i + k - 1;
            ans += (long long) (cnt[r] + 1);
            // auto it = upper_bound(cnt.begin(), cnt.end(), 0)
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}