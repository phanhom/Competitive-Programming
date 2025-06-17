#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    map<int, int> r, c;
    int n, m, mx = 0, mx2 = 0, dc = -1, dr = -1;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m)), b;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            mx2 = max(mx2, a[i][j]);
        }
    }
    b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == mx) {
                r[i] ++;
                if(r[i] > 1) dr = i;
                else if(dr == -1) dr = i;
            }
        }
    }
    if(dr != -1) {
        for(int i = 0; i < m; i++) {
            if(a[dr][i] == mx) a[dr][i] -= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == mx) {
                c[j] ++;
                if(c[j] > 1) dc = j;
                else if(dc == -1) dc = j;
            }
        }
    }
    if(dc != -1) {
        for(int i = 0; i < n; i++) {
            if(a[i][dc] == mx) a[i][dc] -= 1;
        }
    }

    mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mx = max(mx, a[i][j]);
        }
    }

    a = b;
    dc = -1, dr = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == mx2) {
                if(c[j] > 1) dc = j;
                else if(dc == -1) dc = j;
            }
        }
    }
    if(dc != -1) {
        for(int i = 0; i < n; i++) {
            if(a[i][dc] == mx2) a[i][dc] -= 1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == mx2) {
                if(r[i] > 1) dr = i;
                else if(dr == -1) dr = i;
            }
        }
    }
    if(dr != -1) {
        for(int i = 0; i < m; i++) {
            if(a[dr][i] == mx2) a[dr][i] -= 1;
        }
    }


    mx2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mx2 = max(mx2, a[i][j]);
        }
    }
    cout << min(mx, mx2) << endl;
    
}

 
int main() {
    
    int tc;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}