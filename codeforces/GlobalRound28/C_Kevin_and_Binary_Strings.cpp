#include <bits/stdc++.h>

#define ll long long

using namespace std;



void solve() {
    std::string s;
    std::cin >> s;
    int sz = s.size();

    std::cout << 1 << ' ' << s.size() << ' ';

    bitset<5010> s1(s);
    int first_zero = sz - 1;
    for(int i = 0; i < sz; i ++) {
        if(s[i] == '0') {
            first_zero = i;
            break;
        }
    }

    int len = sz - first_zero;
    int ans_l = first_zero,  ans_r = sz - 1;
    string ans_s = s;

    for(int l = first_zero; l >= 0; l --) {
        bitset<5010> sub(s.substr(l, len));
        auto tt = s1;
        sub ^= tt;
        string tmp = sub.to_string();
        tmp = tmp.substr(5010 - sz, sz);

        if(tmp >= ans_s) {
            ans_l = l;
            ans_r = l + len - 1;
            ans_s = tmp;
        }
    }

    std::cout << ans_l + 1 << ' ' << ans_r + 1 << std::endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}