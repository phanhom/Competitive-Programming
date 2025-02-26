#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    map<int, int> s;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 1; i <= n; i ++) s[i] = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s[a[i]] += 1;
    }

    int cnt = 0;

    for(int i = n; i >= 0; i --) {
     
        s[i] -= cnt;
        if(s[i] > 0) cnt = (s[i] & 1);
        else if(cnt != 0) cnt = (abs(s[i])) + 2;


    }
    if(cnt) cout << "NO\n";
    else cout << "YES\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}