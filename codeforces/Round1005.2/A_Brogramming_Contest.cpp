#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // int n = s.size();
    // cout << s;
    int zero = 0;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i --) {
        // cout << s[i] << '-';
        if(s[i] == '0') zero = 1;
        else if(s[i] == '1') {
            // cout << '';
            if(zero) cnt += 2;
            else cnt += 1;
            while(i >= 0 && s[i] == '1') {
                i --;
            }
            i++;
        }
    }
    cout << cnt << endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}