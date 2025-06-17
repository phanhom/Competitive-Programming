#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << abs(a[0] - s) << endl;
        return;
    }
    if(a[0] >= s) {
        cout << abs(a.back() - s) << endl;
        return;
    }
    if(a[n - 1] <= s) {
        cout << s - a[0] << endl;
        return;
    }
    cout << abs(min(a[n - 1] - s, s - a[0])) * 2 + abs(max(a[n - 1] - s, s - a[0])) << endl;
}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}