#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int tmp;

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << "\n";
    fflush(stdout);
    cin >> tmp;
    return tmp;
}

void solve() {
    int n;
    cin >> n;
    int i = 1, j = n - 1, k = n;
    int idx = 0;
    while(true) {
        int tmp_ans = query(i, j, k);
        if(tmp_ans <= 0) {
            cout << "! " << i << " " << j << " " << k << "\n";
            fflush(stdout);
            return;
        } else {
            // idx ++;
            if (idx >= 25 && idx <= 50) k = tmp_ans;
            else if (idx > 50) j = tmp_ans; 
            else i = tmp_ans;
            idx ++;
            // if(idx == 1) {
            //     i = tmp_ans;
            // } else if(idx == 2) {
            //     j = tmp_ans;
            // } else {
            //     k = tmp_ans;
            // }
            // idx %= 3;
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
