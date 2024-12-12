#include <bits/stdc++.h>

// https://codeforces.com/contest/2050

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        std::string tmp;
        std::cin >> tmp;
        nums[i] = tmp.size();
    }
    // std::sort(nums.begin(), nums.end());

    int ans = 0;
    while(m > 0) {
        m -= nums[ans];
        ans++;
    }
    
    ans = m < 0 ? ans - 1 : ans;

    std::cout << std::min(ans, n) << '\n';
}

int main()
{
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
