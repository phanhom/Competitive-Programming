#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k, all = 0, res = 0;
    cin >> n >> m >> k;
    vector<string> s(n);
    vector<vector<int> > nums(n + 1, vector<int>(m + 1));
    set<pii> st;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'g') {
                nums[i + 1][j + 1] = 1;
                all++;
            } else if(s[i][j] == '.') {
                st.insert(pii(i + 1, j + 1));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            nums[i][j] += nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
        }
    }
    for(auto pt : st) {
        int row = pt.first, col = pt.second;
        int rb = nums[min(n, row + k - 1)][min(m, col + k - 1)];
        int lb = nums[min(n, row + k - 1)][max(0, col - k)];
        int rt = nums[max(0, row - k)][min(m, col + k - 1)];
        int lt = nums[max(0, row - k)][max(0, col - k)];
        int tmp_nums = rb - lb - rt + lt; 
        res = max(res, all - tmp_nums);
    }
    cout << res << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}