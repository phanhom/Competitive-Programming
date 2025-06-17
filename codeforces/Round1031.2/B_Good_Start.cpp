#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

void solve() {
    int w, h, a, b, xx, yy, xx2, yy2;
    cin >> w >> h >> a >> b;
    cin >> xx >> yy >> xx2 >> yy2;
    if(xx > xx2) {
        swap(xx, xx2);
        swap(yy, yy2);
    }
    if(xx + a > xx2) {
        if((abs(yy - yy2) - b) % b == 0) {
            cout << "yes\n";
            return;
        }
    } else if(xx + a == xx2) {
        cout << "yes\n";
        return;
    } else if(xx + a < xx2) {
        if(abs(yy - yy2) < b) {
            if(abs(xx2 - xx - a) % a != 0) {
                cout << "no\n";
                return;
            }
        }
        if(abs(xx2 - xx - a) % a == 0) {
            cout << "yes\n";
            return;
        } else if(abs(yy - yy2 - b) % b == 0) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tc = 1;
    std::cin >> tc;
    while (tc--) { solve(); }
    
    return 0;
}