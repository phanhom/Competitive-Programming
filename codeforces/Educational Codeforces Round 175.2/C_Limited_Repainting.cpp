#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k, cntb = 0;
    string s;
    cin >> n >> k >> s;
    vector<int> a(n), b;
    for(int i = 0; i < n; i ++) cin >> a[i];
    bool first_is_b = false;
    if(s[0] == 'B') first_is_b = true;
    for(int i = 0; i < n; i ++) {
        int mx = a[i];
        if(s[i] == 'B') cntb ++;
        for(int j = i + 1; j < n; j ++) {
            if(s[i] == s[j]) {
                mx = max(mx, a[j]);
            } else {
                i = j - 1;
                break;
            }
        }
        b.push_back(mx);
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}