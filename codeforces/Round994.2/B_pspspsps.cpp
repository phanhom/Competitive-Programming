#include <bits/stdc++.h>

// #define ll long long

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int firstp = n, lasts = n;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 's') lasts = i;
        if(s[i] == 'p' && firstp == n) firstp = i;
    }
    if(firstp == n && lasts == n) {
        cout << "YES\n";
        return;
    }

    vector<int> a(n);
    set<int> no;
    int cnt1 = 0, cnt2 = 1;
    // ??
    for(int i = lasts; i < n; i ++) {
        a[i] = ++cnt1;
        no.insert(a[i]);
    }
    // for(int i = firstp + 1; i < n; i ++) {
    //     no.insert(a[i]);
    // }
    for(int i = firstp; i != n && i >= 0; i --) {
        if(a[i] == 0) {
            a[i] = cnt2;
            if(no.count(cnt2)) {
                cout << "NO\n";
                return;
            }
        }
        cnt2++;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}