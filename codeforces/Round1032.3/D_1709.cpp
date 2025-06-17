#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<pii> op;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if(a[i] > b[i]) {
            op.push_back(make_pair(3, i));
            swap(a[i], b[i]);
        }
    }
    // 对a冒泡排序
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if(a[j] > a[j + 1]) {
                op.push_back(make_pair(1, j));
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if(b[j] > b[j + 1]) {
                op.push_back(make_pair(2, j));
                swap(b[j], b[j + 1]);
            }
        }
    }
    cout << op.size() << endl;
    for (auto it: op) {
        cout << it.first << " " << it.second << endl;
    }
}

 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}