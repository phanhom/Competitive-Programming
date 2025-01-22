#include <bits/stdc++.h>

#define ll long long

void solve() {
    int n;
    std::cin >> n;
    if(n % 33) std::cout << "NO\n";
    else std::cout << "YES\n";
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}