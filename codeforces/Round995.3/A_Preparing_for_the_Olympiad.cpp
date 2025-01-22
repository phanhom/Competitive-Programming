#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int ans = 0;
    for(int i = 0; i <n ; i ++) cin >> a[i];
    for(int i = 0; i <n ; i ++) cin >> b[i];

    for(int i = 0; i < n - 1; i ++) {
        if(a[i] > b[i + 1]) {
            ans += a[i] - b[i + 1];
        }
    }
    ans += a.back();
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}