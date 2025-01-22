#include <bits/stdc++.h>
#define ll long long
// using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << std::max(n, m) + 1 << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}