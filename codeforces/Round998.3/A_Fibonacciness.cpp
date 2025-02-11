#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> ans;
    ans.insert(a + b);
    ans.insert(c - b);
    ans.insert(d - c);
    if(ans.size() == 3) cout << 1 << endl;
    else if(ans.size() == 2) cout << 2 << endl;
    else cout << 3 << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}