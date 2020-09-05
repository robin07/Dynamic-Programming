Ques: (SUBSET SUM) Print true if there is subset in array of given sum else false

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



int subsetSum(vi v, ll sum, ll n) {
	ll dp[n + 1][sum + 1];
	memset(dp, -1, sizeof(dp));
	if (sum == 0) {
		return 1;
	}
	if (n == 0 and sum != 0) {
		return 0;
	}
	if (dp[n][sum] != -1) {
		return dp[n][sum];
	}
	if (v[n - 1] > sum) {
		dp[n][sum] = subsetSum(v, sum, n - 1);
	}
	else {
		dp[n][sum] = subsetSum(v, sum, n - 1) or subsetSum(v, sum - v[n - 1], n - 1);
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

		if (subsetSum(v, sum, n) == 1) {
			cout << "True" << "\n";
		} else {
			cout << "False" << "\n";
		}
	}
}
