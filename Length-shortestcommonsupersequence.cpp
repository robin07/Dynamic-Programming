							SHORTEST COMMON SUPERSEQUENCE

Ques:- Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"

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

int scSupersequence(string a, string b) {
	int n = a.length(), m = b.length();

	int commonlen = longestCommonSubseqTD(a, b, n, m);

	return (n + m - commonlen);
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
		cout << scSupersequence(x, y) << "\n";

	}
}						
