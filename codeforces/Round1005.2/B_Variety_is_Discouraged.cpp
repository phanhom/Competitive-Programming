#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, l = 0, r = 0, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> m;
    for(int i = 0; i < n; ++i) m[a[i]] ++;
    for(int i = 0; i < n; ++i) {
        if(m[a[i]] == 1) {
            int tmp = 0;
            int tl = i;
            while(i < n && m[a[i]] == 1) {
                i ++;
                tmp ++;
            }
            i --;
            if(tmp >= ans) {
                ans = tmp;
                l = tl;
                r = i;
            }
        }
    }
    if(ans == 0) cout << 0 << endl;
    else cout << l + 1 << ' ' << r + 1 << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}