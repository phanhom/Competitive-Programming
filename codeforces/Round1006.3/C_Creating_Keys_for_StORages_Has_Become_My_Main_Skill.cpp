#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    int a = 0, b = 0;
    while(a < n && ((a & x) == a)){
        b |= a;
        a++;
    }
    if(a == n && b != x) a --;
    for(int i = 0; i < n; i ++) {
        cout << (i < a ? i : x) << ' ';
    }
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