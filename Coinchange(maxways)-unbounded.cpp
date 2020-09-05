								COIN CHANGE(MAX NO. OF WAYS)

Ques:- Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
Example:
for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

Code:-
//evolvedghost

#include<bits/stdc++.h>
using namespace std;

#define fi              first
#define se              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pai             pair<ll,ll>
#define vi              vector<ll>
#define mpi             map<ll,ll>
#define maxH            priority_queue<ll>
#define minH            priority_queue<ll,vector<ll>,greater<ll>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inp(tc)         int tc; cin>>tc; while(tc--)
#define fast_io         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int coinChangeMaxWays(vi v, ll n, ll sum) {
	ll dp[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= sum; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < v[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			if (j >= v[i - 1]) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - v[i - 1]];
			}
		}
	}
	return dp[n][sum];
}

int main() {
#ifndef ONLINE_JUDGE
	//for reading input from input.txt
	freopen("input3.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output3.txt", "w", stdout);
#endif

	fast_io;
	inp(tc) {
		ll n, sum;
		cin >> n >> sum;
		vi v;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			v.pb(a);
		}

		cout << coinChangeMaxWays(v, n, sum) << "\n";
	}
}
