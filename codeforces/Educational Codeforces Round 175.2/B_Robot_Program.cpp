#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    ll n, x, k;
    string s;
    cin >> n >> x >> k;
    vector<ll> a(n + 1);
    cin >> s;

    ll first = -1LL;

    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == 'L') a[i] = a[i - 1] - 1;
        else a[i] = a[i - 1] + 1;
        if(a[i] == 0 && first == -1) first = i;
    }

    ll second1 = -1LL, second2 = -1LL, ans = 0LL;
    for(ll i = 1LL; i <= n; i++) {
        if(x + a[i] == 0 && i <= k) {
            second1 = i;
            k -= i;
            ans = 1;
            break;
        }
    }

    if(second1 != -1LL) {
        if(first != -1LL) {
            ans += (k / first);
        }
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