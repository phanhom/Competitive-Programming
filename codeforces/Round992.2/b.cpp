#include<bits/stdc++.h>


void solve()
{
	int n, tmp = 1, ans = 1, turn = true;
	std::cin >> n;
	while(n > tmp)
	{
		if(turn)
		{
			tmp ++;
			ans ++;
		}
		else tmp *= 2;

		turn ^= 1;
	}
	std::cout << ans << std::endl;
}

int main()
{
    int tc;
    std::cin >> tc;
    while(tc--) { solve(); }
}
