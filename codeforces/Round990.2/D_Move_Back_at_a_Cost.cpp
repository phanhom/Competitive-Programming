#include <bits/stdc++.h>

#define ll long long
const int mx = 1e9+1;

using namespace std;

void solve() {
    int n, mn = mx;
    cin >> n;
    vector<int> a(n), seq, rest, state(n);
    map<int, vector<int> > idx;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    int start = 0;
    for(auto k : idx) {
        for(int i : k.second) {
            if(i >= start && (mn == mx || k.first - mn < 2)) {
                seq.push_back(a[i]);
                start = i;
                state[i] = 1;
                cout << a[i] << ' ';
            } else {
                mn = min(mn, k.first);
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        if(state[i] == 0) rest.push_back(a[i]);
    }
    sort(rest.begin(), rest.end());
    for(int i : rest) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}