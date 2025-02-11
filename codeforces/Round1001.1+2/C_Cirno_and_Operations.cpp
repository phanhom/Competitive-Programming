#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n;
    ll tt = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        tt += a[i];
    }
    ll sum1 = tt, sum2 = tt;
    vector<ll> b = a;
    reverse(b.begin(), b.end());
    int t1 = n, t2 = n;
    while(t1) {
        ll tsum = a[0];
        for(int i = 0; i < t1 - 1; i ++) {
            a[i] = a[i + 1] - a[i];
            tsum += a[i + 1];
        }
        if(t1 != n) tsum = abs(tsum);
        t1 --;
        sum1 = max(sum1, tsum);
    }
    while (t2) {
        ll tsum = b[0];
        for(int i = 0; i < t2 - 1; i ++) {
            b[i] = b[i + 1] - b[i];
            tsum += b[i + 1];
        }
        if(t2 != n) tsum = abs(tsum);
        t2 --;
        sum2 = max(sum2, tsum);
    }
    cout << max(sum1, sum2) << endl;
    
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}