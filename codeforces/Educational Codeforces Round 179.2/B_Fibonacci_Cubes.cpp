#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

bool judge(int l, int w, int h, int len) {
    if(l >= len && w >= len && h >= len) {
        return true;
    }
    return false;
}

void solve() {
    vector<int> f(11, 1);
    for(int i = 2; i <= 10; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        bool flag = false;
        cin >> a >> b >> c;
        if(judge(a, b, c, f[n])) {
            if(max(a, max(b, c)) >= (f[n] + f[n - 1])) {
                flag = true;
                cout << '1';
            }
        }
        if(flag == false) {
            cout << '0';
        }
    }
    cout << endl;
    return;
}

 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}