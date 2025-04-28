#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if(s[0] == s[n - 1]) {
        if(s[0] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
        return;
    }
    if(s[n - 1] == 'B') {
        for(int i = 1; i < n - 1; i ++) {
            if(s[i] == 'B') {
                cout << "Bob\n";
                return;
            }
        }
        cout << "Alice\n";
        return;
    } else {
        if(s[n - 2] == 'B') {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
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
