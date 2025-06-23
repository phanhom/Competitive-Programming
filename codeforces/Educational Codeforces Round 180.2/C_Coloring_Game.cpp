#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = a[n - 1];

    ll count = 0;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            auto it_lower_bound_sum = upper_bound(a.begin() + j + 1, a.begin() + n - 1, mx - (ll)a[i] - a[j]);
            auto it_upper_bound_val = lower_bound(a.begin() + j + 1, a.begin() + n - 1, (ll)a[i] + a[j]);
            
            if (it_lower_bound_sum < it_upper_bound_val) {
                count += (it_upper_bound_val - it_lower_bound_sum);
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) { 
        auto it = upper_bound(a.begin() + i + 1, a.begin() + n - 1, mx - a[i]);
        count += (a.begin() + n - 1) - it;
    }
    cout << count << endl;

}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}