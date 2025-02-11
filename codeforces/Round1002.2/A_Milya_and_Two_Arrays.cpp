#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    if(a.size() + b.size() > 3) puts("YES");
    else puts("NO");
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}