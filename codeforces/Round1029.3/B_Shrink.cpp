#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int idx = 1;
    for(int i = 0; i < n / 2; i ++) {
        a[i] = idx;
        idx ++;
        a[n - i - 1] = idx;
        idx ++;
    }
    if(n & 1) {
        a[n / 2] = idx;
    }
    for(auto i : a) cout << i << ' ';
    cout << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}