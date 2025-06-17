#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    string s, s2;
    cin >> n >> s;
    s2 = s;
    reverse(s2.begin(), s2.end());
    set<int> st, st2;
    for(int i = 0; i < n - 1; i ++) {
        if(st.count(s[i])) {
            cout << "Yes\n";
            return;
        }
        st.insert(s[i]);
        if(st2.count(s2[i])) {
            cout << "Yes\n";
            return;
        }
        st2.insert(s2[i]);
    }

    cout << "No\n";
}
 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}