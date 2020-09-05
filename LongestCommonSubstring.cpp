						LONGEST COMMON SUBSTRING

Ques:-Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.	

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

int longestCommonSubstringBU(string a, string b) {
	int n = a.size();
	int m = b.size();
	int ans=0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans=max(ans,dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}
	return ans;
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

		cout << longestCommonSubstringBU(x, y) << "\n";
	}
}				
