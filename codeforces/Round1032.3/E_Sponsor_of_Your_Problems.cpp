#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length() < s2.length()) swap(s1, s2);
    int sz = s1.length();
    if(sz != s2.length()) {
        s2 = string(sz - s2.length(), '0') + s2;
    }

    vector<vector<int> > f(10, vector<int>(10, 0x3f3f3f3f));
    for(int i = 0; i < 10; ++i) f[0][i] = 0;
    vector<vector<pii> > bd(10, vector<pii>(10));//下一位上限 下限
    for(int i = 0; i < sz; ++i) {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        if(i == 0) {
            bd[i][b].first = 10;
            bd[i][a].second = -1;
            bd[i][b].second = s1[i + 1] - '0';
            bd[i][a].first = s1[i + 1] - '0';
            f[i][a] += 1;
            f[i][b] += 1;
            for(int j = b + 1; j <= a - 1; ++j) {
                bd[i][j].first = 10;
                bd[i][j].second = -1;
                f[i][j] += 1;
            }
        } else {
            for(int j = 0; j <= 9; ++j) {   // 上一位选哪个
                if(f[i][j] == -1) continue;
                else {
                    int up = bd[i - 1][j].first;
                    int down = bd[i - 1][j].second;
                    if(up == 10) {
                        bd[i][9].first = 10;
                    }
                    if(down == -1) {
                        bd[i][0].second = -1;
                    }
                    bd[i][down].first = 10;
                    bd[i][up].second = -1;
                    bd[i][down].second = s1[i + 1] - '0';
                    bd[i][up].first = s1[i + 1] - '0';

                    for(int k = down + 1; k <= up - 1; ++k) {   // 当前选哪个
                        bd[i][k].first = 10;
                        bd[i][k].second = -1;
                        // f[i][k] = min()
                    }
                    
                }
            }
        }
    }
}

 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}