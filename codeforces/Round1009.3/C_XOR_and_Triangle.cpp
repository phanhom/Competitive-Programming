#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = std::pair<int, int>;

string intToBinaryString(int x) {
    string res;
    while (x > 0) {
        res += (x % 2) + '0';
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

int binaryStringToInt(const string& binX) {
    int res = 0;
    for (char c : binX) {
        res = (res << 1) | (c - '0');
    }
    return res;
}

void solve() {
    int x;
    cin >> x;
    if(x == 2) {
        cout << "-1\n";
        return;
    }
    string ss = intToBinaryString(x);
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < ss.size(); i++) {
        if(ss[i] == '1') cnt1 ++;
        else cnt0++;
    }
    if(cnt1 == 1 || cnt0 == 0) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i + 1 < ss.size(); i++) {
        if(ss[i] == '1' && ss[i + 1] == '0') {
            ss[i] = '0';
            ss[i + 1] = '1';
            break;
        }
    }
    
    cout << binaryStringToInt(ss) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
