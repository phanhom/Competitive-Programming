#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string ans(n + m, '0');


    if(n >= m) {
        if(n == m) {
            for(int i = 1; i <= m; i ++) ans[i * 2 - 2] = '1';
        }
        else for(int i = 1; i <= m; i ++) ans[i * 2 - 1] = '1';
        int bal = 0, cnt = 0;
        for(int i = n + m - 1; i >= 0; i --) {
            bal ++;
            if(ans[i] == '1') {
                ans[i] = '0';
                cnt ++;
            }
            if(bal >= k) {
                for(int j = i - 1; j >= 0 && cnt > 0; j --) {
                    if(ans[j] == '0') {
                        ans[j] = '1';
                        cnt --;
                    }
                }
                break;
            }
        }
        int check = 0;
        for(int i = n + m - 1; i >= 0; i --) {
            if(ans[i] == '1') break;
            check ++;
        }
        if(check != k) {
            cout << "-1\n";
            return;
        }
    } else {
        for(char &c : ans) c = '1';
        for(int i = 1; i <= n; i ++) ans[i * 2 - 1] = '0';
        int bal = 0, cnt = 0;
        for(int i = n + m - 1; i >= 0; i --) {
            bal ++;
            if(ans[i] == '0') {
                ans[i] = '1';
                cnt ++;
            }
            if(bal >= k) {
                for(int j = i - 1; j >= 0 && cnt > 0; j --) {
                    if(ans[j] == '1') {
                        ans[j] = '0';
                        cnt --;
                    }
                }
                break;
            }
        }
        int check = 0;
        for(int i = n + m - 1; i >= 0; i --) {
            if(ans[i] == '0') break;
            check ++;
        }
        if(check != k) {
            cout << "-1\n";
            return;
        }
    }
    int cnt1 = 0, cnt0 = 0;
    for(char &c : ans) {
        if(c == '0') cnt0 ++;
        else cnt1 ++;
    }
    if(!(cnt1 == m && cnt0 == n)) {
        cout << "-1\n";
        return;
    }
    cout << ans << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}