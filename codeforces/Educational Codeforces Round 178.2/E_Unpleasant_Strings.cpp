#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<long long> > next_pos(n + 1, vector<long long>(k, n));
    for (long long i = n - 1; i >= 0; --i) {
        for (long long c = 0; c < k; ++c) {
            next_pos[i][c] = next_pos[i + 1][c];
        }
        next_pos[i][s[i] - 'a'] = i;
    }

    vector<vector<long long> > cnt(k, vector<long long>(n + 1, 0));
    for (long long i = 0; i < n; ++i) {
        for (long long c = 0; c < k; ++c) {
            cnt[c][i + 1] = cnt[c][i] + (s[i] == ('a' + c) ? 1 : 0);
        }
    }

    vector<vector<bool> > exists(k, vector<bool>(n + 1, false));
    for (long long i = n - 1; i >= 0; --i) {
        exists[s[i] - 'a'][i] = true;
        for (long long c = 0; c < k; ++c) {
            if (c != s[i] - 'a') {
                exists[c][i] = exists[c][i + 1];
            }
        }
    }

    long long q;
    cin >> q;
    while (q--) {
        string ti;
        cin >> ti;
        long long m = ti.size();
        if (m == 0) {
            cout << 0 << '\n';
            continue;
        }

        long long j = 0;
        bool valid = true;
        for (char ch : ti) {
            long long c = ch - 'a';
            if (j >= n || next_pos[j][c] == n) {
                valid = false;
                break;
            }
            j = next_pos[j][c] + 1;
        }

        if (!valid) {
            cout << 0 << '\n';
            continue;
        }

        long long L = j;
        if (L >= n) {
            cout << 1 << '\n';
            continue;
        }

        bool all_present = true;
        for (long long c = 0; c < k; ++c) {
            if (!exists[c][L]) {
                all_present = false;
                break;
            }
        }

        if (!all_present) {
            cout << 1 << '\n';
        } else {
            long long min_count = 0x3f3f3f3f;
            for (long long c = 0; c < k; ++c) {
                long long current = cnt[c][n] - cnt[c][L];
                if (current < min_count) {
                    min_count = current;
                }
            }
            cout << min_count + 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    while (t--) {
        solve();
    }
}
