#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int> > a(n, std::vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            std::cin >> a[i][j];
        }
    }

    vector<vector<long long> > f1(n + 1, vector<long long>(n + 1));
    vector<vector<long long> > fr(n + 1, vector<long long>(n + 1));
    vector<vector<long long> > fc(n + 1, vector<long long>(n + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        f1[i + 1][j + 1] = f1[i + 1][j] + f1[i][j + 1] - f1[i][j] + a[i][j];
        fr[i + 1][j + 1] = fr[i + 1][j] + fr[i][j + 1] - fr[i][j] + a[i][j] * i;
        fc[i + 1][j + 1] = fc[i + 1][j] + fc[i][j + 1] - fc[i][j] + a[i][j] * j;
      }
    }
    for (int it = 0; it < q; it++) {
      int i1, j1, i2, j2;
      cin >> i1 >> j1 >> i2 >> j2;
      --i1; --j1;
      int w = j2 - j1;
      // sum a[i][j] * ((i - i1) * w + (j - j1) + 1)
      auto sum_1 = f1[i2][j2] - f1[i1][j2] - f1[i2][j1] + f1[i1][j1];
      auto sum_r = fr[i2][j2] - fr[i1][j2] - fr[i2][j1] + fr[i1][j1];
      auto sum_c = fc[i2][j2] - fc[i1][j2] - fc[i2][j1] + fc[i1][j1];
      auto ans = sum_r * w + sum_c + sum_1 * (-i1 * w - j1 + 1);
      cout << ans << " \n"[it == q - 1];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}