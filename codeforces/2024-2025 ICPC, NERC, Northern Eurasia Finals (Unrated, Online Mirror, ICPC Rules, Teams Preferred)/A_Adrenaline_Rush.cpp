#include <bits/stdc++.h>
#include <utility>

int n, ans = 0;
bool ot[1010][1010];
int origin[1010], c[1010];
std::vector<int> pairs;

void solve() {
    memset(ot, true, sizeof ot);
    int n, ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i ++) {
        origin[i] = i + 1;
        std::cin >> c[i];
    }

    for(int i = 0; i < n; i ++) {
        int target = c[i];
        int target_index = i;
        for(int j = i + 1; j < n; j ++) {
            if(origin[j] == target) target_index = j;
        }

        for(int j = target_index; j > i; j --) {
            std::swap(origin[j - 1], origin[j]);
            pairs.push_back(origin[j-1]);
            pairs.push_back(origin[j]);
            ot[origin[j-1]-1][origin[j]-1] = false;
            ans += 1;
        }
    }


    for(int i = 0; i < n - 1; i ++) {
        if(ot[c[i] - 1][c[i+1] - 1] && ot[c[i+1]-1][c[i]-1]) {
            ans += 2;
            pairs.push_back(c[i + 1]);
            pairs.push_back(c[i]);
            pairs.push_back(c[i]);
            pairs.push_back(c[i+1]);
        }
    }
    std::cout << ans << '\n';
    for(int i = 0; i < pairs.size(); i += 2) {
        std::cout << pairs[i] << ' ' << pairs[i + 1] << '\n';
    }



}

int main() {
    int tc = 1;
    // std::cin >> tc;
    while(tc --) { solve(); }
}