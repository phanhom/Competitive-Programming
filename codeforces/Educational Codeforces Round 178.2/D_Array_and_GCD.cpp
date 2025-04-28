#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> primes;

void generate_primes(ll max_count) {
    primes.clear();
    primes.reserve(max_count);
    primes.push_back(2ll);
    ll num = 3ll;
    while (primes.size() < max_count) {
        bool is_prime = true;
        for (ll p : primes) {
            if (p * p > num) break;
            if (num % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(num);
        }
        num += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    generate_primes(400000); // 生成前40万个质数
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        
        ll coins = 0, idx = 0;
        for(ll i = 0; i < n; i ++) {
            if(coins + a[i] >= primes[i]) {
                coins = coins + a[i] - primes[i];
                idx ++;
            }
            else {
                break;
            }
        }
        
        cout << n - idx << endl;
    }
    return 0;
}