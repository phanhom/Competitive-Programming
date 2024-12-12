#include <bits/stdc++.h>

// https://codeforces.com/contest/2050

void solve()
{
    long long n, odd = 0, even = 0;
    std::cin >> n;
    std::vector<long long> nums(n);

    for(int i = 0; i < n; i ++) {
        std::cin >> nums[i];
        if(i & 1) even += nums[i];
        else odd += nums[i];
    }

    std::string ans;
    if(even % (n / 2) || odd % (n / 2 + n % 2)) ans = "NO";
    else if(even / (n / 2) == odd / (n / 2 + n % 2)) ans = "YES";
    else ans = "NO";

    std::cout << ans << '\n';
}

int main()
{
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
