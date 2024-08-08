#include<bits/stdc++.h>
using namespace std;
#define make_it_fast ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
 
#define MOD 1000000007
 
int  main() {
	make_it_fast;
 
	int n;
	cin >> n;
 
	int sum = (n * (n + 1) / 2) / 2;
 
	if ((n * (n + 1) / 2) % 2 == 0) {
		vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
 
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= sum; j++) {
				if (j == 0) {
					dp[i][j] = 1;
				}
				else {
					long long op1 = (j < i) ? 0 : dp[i - 1][j - i];
					long long op2 = (i == 1) ? 0 : dp[i - 1][j];
					dp[i][j] = ((op1 % MOD) + (op2 % MOD)) % MOD;
				}
			}
		}
 
		cout << dp[n][sum] << "\n";
	}
	else {
		cout << 0 << "\n";
	}
 
}