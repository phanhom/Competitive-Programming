#include <bits/stdc++.h>

// https://codeforces.com/contest/2050

void solve()
{
    std::string s;
    std::cin >> s;
    std::vector<int> dig(10);
    int sum = 0;

    for(int i = 0; i < s.length(); i ++) {
        dig[s[i] - '0'] ++;
        sum += (s[i] - '0');
    }

    while(sum >= 10) {
        int tmp = 0;
        while(sum) {
            tmp += sum % 10;
            sum /= 10;
        }
        sum = tmp;
    }
    if(sum == 0) {
        std::cout << "YES\n";
        return;
    }
    // std::cout << sum << ' ';

    if(sum & 1) {
        if(dig[3] && (sum == 1 || sum == 3)) {
            sum += 6;
        }
        if(dig[2] >= (9 - sum) / 2) {
            std::cout << "YES\n";
            return;
        } else {
            std::cout << "NO\n";
        }
    } else {
        while(dig[3] && (18 - sum) >= 6) {
            sum += 6;
            dig[3] --;
        }
        while(dig[2] && (sum != 18)) {
            sum += 2;
            dig[2] --;
        }
        if(sum == 18) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}

int main()
{
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}
