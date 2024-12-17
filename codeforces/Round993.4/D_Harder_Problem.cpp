#include <bits/stdc++.h>


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::vector<bool> st(n);
    for(int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        if(st[tmp - 1]) nums[i] = -1;
        else nums[i] = tmp;
        st[tmp - 1] = true;
    }
    int flo = 0;
    for(int i = 0; i < n;  i++) {
        if(nums[i] == -1) {
            while(flo < n && st[flo] == true) {
                flo += 1;
            }
            nums[i] = flo + 1;
            flo++;
        }
    }
    for(int i = 0; i < n; i ++) std::cout << nums[i] << " \n"[i == n - 1];
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}