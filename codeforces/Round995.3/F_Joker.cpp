#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int l = m, r = m, x = 0, y = 0;
    bool f = 0, k = 0;
    while (q--)
    {
        int a;
        cin >> a;
        if (a >= l and a <= r)
        {
            f = 1;
            if (l == r) k = 1;
        }
        else if (a < l) l--;
        else if (a > r) r++;
        if (f and a > x) x++;
        if (f and a < n - y + 1) y++;
        if (k) cout << min(n, x + y); 
        else cout << (r - l + 1) + min(l - 1, x) + min(n - r, y); 
        cout << " \n"[q == 0];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while (tc--)
    {
        solve();
    }
}