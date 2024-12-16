#include <bits/stdc++.h>


void solve() {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == 'p') s[i] = 'q';
        else if(s[i] == 'q') s[i] = 'p';
    }
    std::cout << s << std::endl;
}

int main() {
    int tc = 1;
    std::cin >> tc;
    while(tc--) { solve(); }
}