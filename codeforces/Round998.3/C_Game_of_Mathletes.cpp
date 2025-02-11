#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k, tmp = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(n * 2, 0);
    for(int i = 0; i < n; i ++) {
        cin >> tmp;
        a[tmp] ++;
    }
    for(int i = 1; i < k / 2; i ++) {
        ans += min(a[i], a[k - i]);
    }
    if(k & 1) ans += min(a[k/2], a[k/2 + 1]);
    else ans += a[k/2]/2;
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