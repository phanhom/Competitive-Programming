#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);//, l(n), g(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int ansl = 1, ansr = 1;

    // for(int i = 0; i < n; i ++) {
    //     for(int j = i + 1; j < n; j ++) {
    //         if(a[i] > a[j]) {
    //             l[i] ++;
    //         } else if(a[i] < a[j]) {
    //             g[i] ++;
    //         }
    //     }
    // }
    
    for(int i = 0; i < n; i ++) {
        int cntl = 0, cntg = 0;
        for(int j = i + 1; j < n; j ++) {
            if(a[i] > a[j]) cntl ++;
            if(a[i] < a[j]) cntg ++;
            if(cntl - cntg > ans) {
                ans = cntl - cntg;
                ansl = i + 1, ansr = j + 1;
            }
        }
    }
    cout << ansl << ' ' << ansr << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}