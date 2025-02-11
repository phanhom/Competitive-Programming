#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> mp1, mp2;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        mp1[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
        mp2[b[i]]++;
    }

    if (std::accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll))
    {
        std::cout << "No\n";
        return;
    }

    while (!mp2.empty() && n)
    {
        auto [x, y] = *mp2.rbegin();
        mp2.erase(x);
        if (mp1.count(x))
        {
            int match = std::min(mp1[x], y);
            mp1[x] -= match;
            y -= match;
            n -= match;
            if (mp1[x] == 0)
            {
                mp1.erase(x);
            }
        }

        if (y)
        {
            if (x == 1)
            {
                break;
            }
            mp2[x / 2] += y;
            mp2[x - x / 2] += y;
        }
    }

    if (!n)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
}
