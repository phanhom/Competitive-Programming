#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), max_from_left(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i) max_from_left[i] = max(max_from_left[i - 1], a[i]);
        else max_from_left[i] = a[i];
    }
    // for(int i = n - 1; i >= 0; i --) {
    //     if(i == n - 1) min_from_right[i] = a[i];
    //     else min_from_right[i] = min(min_from_right[i + 1], a[i]);
    // }
    long long sum = 0;
    for(int i = n - 1; i >= 0; i --) {
        sum += (long long)a[i];
        int mx = max_from_left[i - 1];
        if(i && mx > a[i]) cout << (long long)sum +  mx - a[i] << " ";
        else cout << sum << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
