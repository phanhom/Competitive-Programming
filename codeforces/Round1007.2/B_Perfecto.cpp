#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

bool is_square(ll n) {
    ll sq = sqrt(n);
    return sq * sq == n;
}

void solve() {
    int n;
    cin >> n;
    vector<bool> st(n + 1);
    vector<int> ans;
    ll sum = 0;
    for(int i = 1; i <= n;) {
        if(st[i]) {
            i ++;
            continue;
        }
        ll j = i;
        while(is_square((ll)sum + j) || (j <= n && st[j])) {
            j += 1;
        }
        if(j > n) {
            cout << "-1\n";
            return;
        }
        sum += j;
        st[j] = true;
        ans.push_back(j);
        if(st[i]) {
            i ++;
        }
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}