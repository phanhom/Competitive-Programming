#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

int tmp;

int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    cin >> tmp;
    return tmp;
}

void answer(string ans) {
    cout << "! " << ans << endl;
    cout.flush();
}

void solve() {
    int n, first_01 = 0;
    cin >> n;
    string ans(n + 1, '0');
    for(int i = 1; i < n; i ++) {
        if(query(i, i + 1) > 0) {
            first_01 = i + 1;
            break;
        }
    }
    if(!first_01) {
        answer("IMPOSSIBLE");
        return;
    }
    ans[first_01] = '1';
    int t = query(1, first_01);
    int prefix_1 = first_01 - t;
    for(int i = 1; i < prefix_1; i ++) {
        ans[i] = '1';
    }
    for(int i = first_01 + 1; i <= n; i ++) {
        int tt = query(1, i);
        if(tt > t) ans[i] = '1';
        t = tt;
    }
    answer(ans.substr(1));
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}