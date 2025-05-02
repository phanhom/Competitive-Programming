#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    if(x == 1) {
        if(n == 1) cout << 1 << endl;
        else if(n & 1) {
            cout << n << endl;
        } else {
            cout << n + 3 << endl;
        }
        return;
    }
    int cnt = 0, tmpn = x;
    while(tmpn) {
        cnt += (tmpn & 1);
        tmpn >>= 1;
    }

    if(x == 0) {
        if(n == 1) cout << -1 << endl;
        else if(n & 1) cout << n + 3 << endl;
        else cout << n << endl;
        return;
    }
    if(cnt >= n) {
        cout << x << endl;
        return;
    }
    if((n - cnt) & 1) {
        cout << x - cnt + n + 1 << endl;
    } else {
        cout << x - cnt + n << endl;
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