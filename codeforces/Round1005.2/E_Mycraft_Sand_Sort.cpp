#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 200000;

// 预处理阶乘和逆阶乘
vector<long long> fact(MAX_N + 1, 1), inv_fact(MAX_N + 1, 1);

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void preprocess_factorials() {
    // 计算阶乘
    for (int i = 2; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // 计算逆阶乘（使用费马小定理）
    inv_fact[MAX_N] = mod_pow(fact[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N - 1; i >= 1; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// 计算排列数 C(n, k)
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    // 预处理阶乘和逆阶乘
    preprocess_factorials();
    
    int t;
    cin >> t;  // 读取测试用例数量
    while (t--) {
        int n;
        cin >> n;  // 数组的长度
        vector<int> p(n), c(n);
        
        for (int i = 0; i < n; i++) {
            cin >> p[i];  // 读取排列 p
        }
        
        for (int i = 0; i < n; i++) {
            cin >> c[i];  // 读取颜色数组 c
        }
        
        // 将 p 和 c 按照 p 排序，确保 p 的位置正确
        vector<pair<int, int> > indexed(n);
        for (int i = 0; i < n; i++) {
            indexed[i] = make_pair(p[i], c[i]);
        }
        
        sort(indexed.begin(), indexed.end());
        
        // 重新生成排序后的 p 和 c
        for (int i = 0; i < n; i++) {
            p[i] = indexed[i].first;
            c[i] = indexed[i].second;
        }
        
        // 统计颜色出现的频率
        map<int, int> color_count;
        for (int i = 0; i < n; i++) {
            color_count[c[i]]++;
        }
        
        // 计算可能的排列数
        long long result = 1;
        for (auto& entry : color_count) {
            result = result * fact[entry.second] % MOD;
        }
        
        // 输出结果
        cout << result << endl;
    }
    
    return 0;
}
