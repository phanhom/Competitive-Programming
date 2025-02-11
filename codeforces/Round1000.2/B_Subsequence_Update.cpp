#include <bits/stdc++.h>
 
using ll = long long;
using pii = std::pair<int, int>;
 
void solve() {
    int n, l , r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    std::vector<int> le(l - 1), mid(r - l + 1), ri(n - r);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(i < l - 1) le[i] = a[i];
        else if(i < r) mid[i - l + 1] = a[i];
        else ri[i - r] = a[i];
    }
    std::sort(le.begin(), le.end());
    std::sort(mid.rbegin(), mid.rend());
    std::sort(ri.begin(), ri.end());
    int idx = 0;
    ll sum = 0, ans = 0;
    for(int i = 0; i < mid.size(); i ++) {
        sum += mid[i];
    }
    ans = sum;
    ll tmp = sum;
    while(idx < le.size() && idx < mid.size()) {
        if (mid[idx] > le[idx]) {
            tmp -= mid[idx] - le[idx];
        } else {
            break;
        }
        idx ++;
    }
    // for(int i : le) std::cout << i << ' ';
    // std::cout << '\n';
    // for(int i : mid) std::cout << i << ' ';
    // std::cout << '\n';
    // for(int i : ri) std::cout << i << ' ';
    ans = std::min(ans, tmp);
    idx = 0;
    tmp = sum;
    while(idx < ri.size() && idx < mid.size()) {
        if (mid[idx] > ri[idx]) {
            tmp += ri[idx] - mid[idx];
        } else {
            break;
        }
        idx ++;
    }
    ans = std::min(ans, tmp);
    std::cout << ans << '\n';


}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}