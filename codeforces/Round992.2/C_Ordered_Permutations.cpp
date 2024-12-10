#include<bits/stdc++.h>

// https://codeforces.com/contest/2040

void solve()
{
	long long n, k;
	std::cin >> n >> k;
    k--;

    if(n <= 40 && k >= (1LL << (n - 1))) {
        std::cout << "-1\n";
        return;
    }

	std::vector<int> arr(n);
	int l = 0, r = n - 1;

	for(int i = 1; i < n; i ++) {
		if((n - i - 1) > 40 || k < (1LL << (n - i - 1))) {
			arr[l++] = i;
		} else {
			arr[r--] = i;
			k -= (1LL << (n - i - 1));
		}
	}
	arr[l] = n;

	for(int i = 0; i < n; i ++) std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main()
{
    int tc;
    std::cin >> tc;
    while(tc--) { solve(); }
}
