#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> nn(n + 1, 0);
    for(int i = 1; i <= n; i ++) {
        cin >> nn[i];
        // cout << nn[i] << ' ';
        if(nn[i] != 0 && nn[i - 1] == 0) cnt ++;
    }
    int ans = 0;
    if(cnt == 1) ans = 1;
    if(cnt > 1) ans = 2;
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