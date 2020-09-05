Ques: Partition a set into two subsets such that the difference of subset sums is minimum.

TC:- O(n*sum)
Code:
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


int minDiff(vi v, ll n) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	bool dp[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}
	for (int i = 1; i <= sum; i++) {
		dp[0][i] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < v[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			if (j >= v[i - 1]) {
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - v[i - 1]];
			}
		}
	}
	int mn;
	for (int i = sum / 2; i >= 0; i--) {
		if (dp[n][i] == true) {
			mn = sum - 2 * i;
			break;
		}
	}
	return mn;
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
		ll n;
		cin >> n;
		vi v;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			v.pb(a);
		}

		cout << minDiff(v, n) << "\n";
	}
}
