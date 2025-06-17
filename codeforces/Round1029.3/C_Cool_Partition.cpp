#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    vector<int> v1(1, a[0]);
    set<int> s1;
    s1.insert(a[0]);
    mp[a[0]]--;
    int idx = 1, ans = 1;
    while(idx < n) {
        for(int i = 0; i < v1.size(); i ++) {
            if(mp[v1[i]] <= 0) {
                cout << ans << endl;
                return;
            }
        }
        set<int> s2;
        vector<int> v2;
        int tmp_num = 0, sz = s1.size();
        while(idx < n) {
            s2.insert(a[idx]);
            v2.push_back(a[idx]);
            mp[a[idx]] --;
            if(s1.count(a[idx])) {
                tmp_num ++;
                s1.erase(a[idx]);
            }
            idx ++;
            if(tmp_num >= sz) {
                break;
            }
        }
        v1 = v2;
        s1 = s2;
        ans ++;
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