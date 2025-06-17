#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3> > a(1);
    cin >> a[0][0];
    a[0][1] = 0;
    a[0][2] = n - 1;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (a.back()[0] != x) {
            array<int, 3> tmp = {x, i, n - i  - 1};
            a.push_back(tmp);
        } else {
            a.back()[2] -= 1;
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f;
    for(auto &i : a) {
        ans = min(ans, 1ll * i[0] * (i[1] + i[2]));
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