						PRINT LONGEST COMMON SUBSEQUENCE

Ques:-
Given two sequences, print the longest subsequence present in both of them.
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

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

string longestCommonSubseqBU(string a, string b) {
	int n = a.size();
	int m = b.size();
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];

			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	string s;
	int i = n, j = m;
	while (i > 0 and j > 0) {
		if (a[i - 1] == b[j - 1]) {
			s.pb(a[i - 1]);
			i--;
			j--;
		} else {
			if (dp[i][j - 1] > dp[i - 1][j]) {
				j--;
			} else {
				i--;
			}
		}
	}
	reverse(s.begin(), s.end());
	return s;
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

		cout << longestCommonSubseqBU(x, y) << "\n";
	}
}
