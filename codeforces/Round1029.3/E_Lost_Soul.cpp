#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, mx = -1;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];

    int aa = -1, bb = -1, ab = -1, aneedb = -1, bneeda = -1, aneedb_ = -1, bneeda_ = -1;
    // for(int i = 0; i < n; i ++) {
    //     if(a[i] == b[i]) ab = i;
    //     if(i < n - 1 && a[i] == a[i + 1]) aa = i;
    //     if(i < n - 1 && b[i] == b[i - 1]) bb = i;
    //     if(i < n - 3 && a[i] == b[i + 3]) aneedb_ = i;
    //     if(i < n - 2 && a[i] == b[i + 2]) aneedb = i;
    //     if(i < n - 3 && b[i] == a[i + 3]) bneeda_ = i;
    //     if(i < n - 2 && b[i] == a[i + 2]) bneeda = i;
    // }
    set<int> ss;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == b[i]) ab = max(ab, i);
        if(i < n - 1 && a[i] == a[i + 1]) aa = max(aa, i);
        if(i < n - 1 && b[i] == b[i + 1]) bb = max(bb, i);
        ss.insert(a[i]);
        ss.insert(b[i]);
        if(i >= 2 && ss.count(a[i - 2])) aa = max(aa, i - 2);
        if(i >= 2 && ss.count(b[i - 2])) bb = max(bb, i - 2);
        // cout << b[i - 2] << "---b[i - 2]" << endl;
    }
    // mx = max(mx, max(aa, max(bb, max(ab, max(aneedb, max(aneedb_, max(bneeda, bneeda_)))))));
    mx = max(mx, max(ab, max(aa, bb)));
    // cout << "aa" << aa << endl;
    // cout << "bb" << bb << endl;
    // cout << "ab" << ab << endl;
    // cout << "mx" << mx << endl;
    cout << mx + 1 << endl;
    
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}