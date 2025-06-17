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
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(a[i] > a[j]) {
                op.push_back(make_pair(1, i));
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(b[i] > b[j]) {
                op.push_back(make_pair(1, i));
                swap(b[i], b[j]);
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