#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

int tmp;

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    cin >> tmp;
    return tmp;
}

void output(string s) {
    cout << s << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i ++) {
        cin >> x[i];
    }
    int a = query(x[0], x[n - 1]);
    int b = query(x[n - 1], x[0]);
    if(a == 0 || b == 0 || min(a, b) <= n / 2) output("! A");
    else if(a == b) output("! B");
    else output("! A");
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}