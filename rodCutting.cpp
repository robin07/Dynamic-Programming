							ROD CUTTING

Ques : Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 

Approach:- initialise a 1d-array called Dp[n+1] where n is length for which we have to find maximum profit
Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.

cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}

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



int rodCutting(vi v, ll n) {
	ll dp[n + 1];
	dp[0] = 0;


	for (int i = 1; i <= n; i++) {
		ll maxval = INT_MIN;
		for (int j = 0; j < i; j++) {
			maxval = max(maxval, (v[j] + dp[i - j - 1]));
			dp[i] = maxval;
		}
	}
	return dp[n];
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
		ll n, len;
		cin >> n >> len;
		vi v;
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			v.pb(a);
		}

		cout << rodCutting(v, len) << "\n";
	}
}
