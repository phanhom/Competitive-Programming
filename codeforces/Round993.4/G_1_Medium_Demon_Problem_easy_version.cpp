#include <bits/stdc++.h>


void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> r(n), start(n), st(n), dep(n);

    for(int i = 0; i < n; i ++) {
        std::cin >> r[i];
        r[i] --;
        start[r[i]] = -1;
    }

    for(int i = 0; i < n; i ++) {
        if(start[i] == 0) {
            // std::cout << i + 1 << ' ';
            // continue;
            st[i] = true;
            std::set<int> pre;
            pre.insert(i);
            int next = r[i];
            while(st[next] == false) {
                st[next] = true;
                pre.insert(next);
                next = r[next];
            }
            while(st[next] && pre.count(next) && start[next] == -1) {
                start[next] = 1;
                next = r[next];
            }
        }
    }

    for(int i = 0; i < n; i ++) {
        // std::cout << i + 1 << '=' << start[i] << ' ';
        // continue;
        if(start[i] == 0) {
            int len = 1, next = r[i];
            // std::cout << i + 1 << ' ';
            while(start[next] != 1) {
                // std::cout << next + 1 << ' ';
                if(len <= dep[next]) break;
                dep[next] = len;
                len ++;
                next = r[next];
            }
            ans = std::max(ans, len);
        }
    }
    // std::cout << std::endl;
    // return;

    std::cout << ans + 2 << '\n';
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}