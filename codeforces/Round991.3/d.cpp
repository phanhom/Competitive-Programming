#include <bits/stdc++.h>

// https://codeforces.com/contest/2050

void solve()
{
    std::string s;
    std::cin >> s;
    int sz = s.size();

    for(int i = 0; i < sz - 1; i ++) {
        int target_index = i, gap = 0;

        for(int j = i + 1; j < std::min(i + 9, sz); j ++) {
            if(s[j] - s[i] - (j - i) > gap) {
                target_index = j;
                gap = s[j] - s[i] - (j - i);
            }
        }

        for(int k = target_index; k > i; k --) {
            s[k] -= 1;
            std::swap(s[k], s[k - 1]);
        }
    }
    std::cout << s << std::endl;
}

int main()
{
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
