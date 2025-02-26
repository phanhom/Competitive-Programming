#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

int calcu(int n) {
    for(int i = 2; i < 10000; i ++) {
        if(i * (i - 1) / 2 > n) return i - 1;
    }
    return 1;
}

void solve() {
    int k, ans = 0;
    cin >> k;
    int y = 1, x = 1;
    vector<int>ansx, ansy;
    while(k > 0) {
        int placed = calcu(k);
        for(int i = 0; i < placed; i ++) {
            ansx.push_back(x + i);
            ansy.push_back(y);
        }
        // cout << placed << '-';
        x += placed;
        y += 1;
        k -= (placed * (placed - 1) / 2);
    }
    cout << ansx.size() << endl;
    for(int i = 0; i < ansx.size(); i ++) {
        cout << ansx[i] << " " << ansy[i] << endl;
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}