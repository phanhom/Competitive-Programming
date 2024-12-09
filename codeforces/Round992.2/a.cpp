#include<bits/stdc++.h>


void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<bool> st(n, true);
    std::vector<int> a(n);
    for(int i = 0; i < n; i ++) std::cin >> a[i];

    for(int i = 0; i < n; i ++)
		for(int j = 0; j < i; j ++)
		{
	    	if(std::abs(a[i] - a[j]) % k == 0)
	   		{
			st[i] = false;
			st[j] = false;
	  		}
		}

    for(int i = 0; i < n; i ++)
		if(st[i])
		{
	    	std::cout << "YES\n" << i + 1 << std::endl;
	    	return;
		}

    std::cout << "NO" << std::endl;
}

int main()
{
    int tc;
    std::cin >> tc;
    while(tc--) { solve(); }
}
