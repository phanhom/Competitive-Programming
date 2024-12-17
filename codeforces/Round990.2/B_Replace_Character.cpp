#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n, mn = 11, mni, mx = 0, mxi;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for(int i = 0; i < n; i ++) cnt[s[i] - 'a'] ++;
    for(int i = 0; i < 26; i ++) {
        if(cnt[i] && cnt[i] < mn) mni = i, mn = cnt[i];
        if(cnt[i] && cnt[i] >= mx) mxi = i, mx = cnt[i];
    }
    // cout << mni << ' ' << mxi << endl;
    for(int i = 0; i < n; i ++) {
        if(s[i] == ('a' + mni)) {
            s[i] = ('a' + mxi);
            cout << s << endl;
            return;
        }
    }
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}