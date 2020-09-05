							LONGEST COMMON SUBSEQUENCE

Ques:- Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
INPUT:- abcde ace
OUTPUT: 3 i.e ace

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

int dp[1001][1001];

int longestCommonSubseqBU(string a, string b) {
	int n = a.size();
	int m = b.size();

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

int longestCommonSubseqTD(string a, string b, int n, int m) {
	if (n == 0 or m == 0) {
		return 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}
	if (a[n - 1] == b[m - 1]) {
		dp[n][m] = 1 + longestCommonSubseqTD(a, b, n - 1, m - 1);
	} else {
		dp[n][m] = max(longestCommonSubseqTD(a, b, n - 1, m), longestCommonSubseqTD(a, b, n, m - 1));
	}
	return dp[n][m];
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
		string x, y;
		cin >> x >> y;
		int n = x.length();
		int m = y.length();

		memset(dp, -1, sizeof(dp));
		cout << longestCommonSubseqTD(x, y, n, m) << "\n";
		cout << longestCommonSubseqBU(x, y) << "\n";
	}
}
