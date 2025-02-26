#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

bool c7(ll u) {
    while(u) {
        if(u % 10 == 7) {
            return true;
        }
        u /= 10;
    }
    return false;
}

void solve() {
    vector<ll> nn;
    ll tmp = 9, ans = 10000, n;
    cin >> n;
    for(int i = 0; i <= 10; i ++) {
        nn.push_back(tmp);
        tmp *= 10;
        tmp += 9;
        // cout << tmp << endl;
    }
    for(ll i = 0; i <= 10; i ++) {
        ll idx = 0;
        while(!c7(idx * nn[i] + n)) {
            idx ++;
        }
        ans = min(ans, idx);
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