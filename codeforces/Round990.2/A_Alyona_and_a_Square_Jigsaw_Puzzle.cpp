#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
set<int> ff;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cur = 0, ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        cur += a[i];
        if(ff.count(cur)) ans ++;
    }
    cout << ans << endl;
}
 
int main() {
    int tc = 1;
    std::cin >> tc;
    int tmp = 1;
    for(int i = 1; i <= 100 * 100; i ++) {
        ff.insert(tmp);
        tmp += i * 8;
    }
    while(tc--) { solve(); }
}