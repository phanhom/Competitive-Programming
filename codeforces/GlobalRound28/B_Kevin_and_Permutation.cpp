#include <bits/stdc++.h>

#define ll long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> ans(n);

    int start = 1;
    for(int i = k - 1; i < ans.size(); i += k) {
        ans[i] = start;
        start ++;
        // if(i + k >= ans.size()) ans[ans.size() - 1] = start++;
    }
    for(int i = 0; i < ans.size(); i ++) {
        if(ans[i] == 0) {
            ans[i] = start;
            start ++;
        }
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}