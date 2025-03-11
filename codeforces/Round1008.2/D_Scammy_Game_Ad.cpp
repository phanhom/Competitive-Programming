#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    ll l = 1, r = 1;
    vector<int> plus_l(n), plus_r(n), multi_l(n), multi_r(n);
    for(int i = 0; i < n; i ++) {
        char lo, ro;
        int ln, rn;
        cin >> lo >> ln;
        cin >> ro >> rn;
        if(lo == '+') plus_l[i] = ln;
        if(ro == '+') plus_r[i] = rn;
        if(lo == 'x') multi_l[i] = ln;
        if(ro == 'x') multi_r[i] = rn;
    }
    ll rest = 0;
    for(int i = 0; i < n; i ++) {
        bool tol = true;
        if(plus_l[i] && plus_r[i]) {
            ll tl = 1, tr = 1;
            for(int j = i; j < n; j ++) {
                if(plus_l[j]) {
                    tl += plus_l[j];
                } else {
                    tl *= multi_l[j];
                }
                if(plus_r[j]) {
                    tr += plus_r[j];
                } else {
                    tr *= multi_r[j];
                }
            }
            if(tr > tl) tol = false;
        } else {
            if(plus_l[i]) {
                tol = false;
            } else if(plus_r[i]) {
                tol = true;
            } else {
                if(multi_l[i] > multi_r[i]) {
                    tol = true;
                } else if(multi_l[i] < multi_r[i]) {
                    tol = false;
                } else {
                    ll tl = 1, tr = 1;
                    for(int j = i; j < n; j ++) {
                        if(plus_l[j]) {
                            tl += plus_l[j];
                        } else {
                            tl *= multi_l[j];
                        }
                        if(plus_r[j]) {
                            tr += plus_r[j];
                        } else {
                            tr *= multi_r[j];
                        }
                    }
                    if(tr > tl) tol = false;
                }
            }
        }
        if(plus_l[i]) {
            rest += plus_l[i];
            // cout << plus_l[i] << " ";
        } else {
            rest += l * multi_l[i] - l;
            // cout << multi_l[i] << endl;
        }
        if(plus_r[i]) {
            rest += plus_r[i];
            // cout << plus_r[i] << " ";
        } else {
            rest += r * multi_r[i] - r;
        }
        // cout << l << endl;
        if(tol) {
            l += rest;
        } else {
            r += rest;
        }
        cout << l << ' ' << r  << ' ' << rest<< endl;
        rest = 0;
    }
    cout << (ll) l + r << endl;
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
