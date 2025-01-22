#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;

    // vector<ll> a(n), b(n);
    vector<pair<ll, int> > a(2 * n), b;
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
        a[i].first += 1LL;
        a[i].second = 1;
        b.push_back(make_pair(a[i].first - 1LL, 4));
    }
    for(int i = 0; i < n; i ++) {
        cin >> a[n + i].first;
        a[n + i].first += 1LL;
        a[n + i].second = 2;
        b.push_back(make_pair(a[n + i].first - 1LL, 3));
    }
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());

    ll cnt = 0, neg = 0;
    ll ans = 0;
    for(int i = 0; i < 4 * n; i ++) {
        // cout << a[i].first << ' ' << a[i].second << endl;
        ll total = n - cnt;
        if(a[i].second == 4) {
            // if(neg > k) continue;
            // ans = max(ans, a[i].first * total);
        }
        if(a[i].second == 1) {
            neg ++;
            // if(neg > k) continue;
            // ans = max(ans, a[i].first * total);
        }
        if(a[i].second == 3) {
            // if(neg > k) continue;
            // ans = max(ans, a[i].first * total);
        }
        if(a[i].second == 2) {
            neg--;
            cnt ++;
            total --;
            // if(neg > k) continue;
            // ans = max(ans, a[i].first * total);
        }
        if(i + 1 < 4 * n && a[i].first == a[i + 1].first) continue;
        if(neg > k) continue;
        ans = max(ans, a[i].first * total);
        // cout << ans << endl;
        // cout << neg << endl;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}