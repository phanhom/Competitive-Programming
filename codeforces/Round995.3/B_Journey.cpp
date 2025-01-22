#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), ft(k), all(n);
    set<int> dk;
    for(int i = 0; i < m; i ++) cin >> l[i];
    for(int i = 0; i < k; i ++) {
        cin >> ft[i];
        all[ft[i] - 1] = 1;
    }

    for(int i = 0; i < n; i ++) {
        if(all[i] == 0) dk.insert(i + 1);
    }
    if(dk.size() >= 2) {
        string t1(n, '0');
        cout << t1 << endl;
        return;
    } else if(dk.size() == 0) {
        string t2(n, '1');
        cout << t2 << endl;
        return;
    }
    string ans = "";
    for(int i = 0; i < m; i ++) {
        if(dk.count(l[i])) {
            ans += '1';
        }
        else {
            ans += '0';
        }
    }
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