#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int l = 1, r = n + 2 - k;
    if(r - l > 1) {
        for(int i = l; i < r; i ++) {
            if(a[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
        return;
    }

    int idx = 1;
    for(int i = l; i < n;) {
        if(a[i] == idx) {
            i += 2;
            idx += 1;
        }
        else {
            break;
        }
    }
    cout << idx << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}