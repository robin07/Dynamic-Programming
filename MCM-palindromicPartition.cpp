							PALINDROME PARTITIONING

Ques:-Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 	Input : str = “aaaa”
Output : 0
The string is already a palindrome.

Input : str = “abcde”
Output : 4

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


/*
bool comparePairs(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return (a.first > b.first);
}

bool compare(int a, int b) {
	return a <= b ;
}
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return ((a * b) / gcd(a, b));
}*/
int dp[1001][1001];

bool isPalindrome(string s, int start, int end) {
	if (start >= end) {
		return true;
	}
	while (start <= end) {
		if (s[start] != s[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}
int minPalPartition(string s, int i, int j) {
	if (i >= j) {
		return 0;
	}
	if (isPalindrome(s, i, j) == true) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int temp, ans = INT_MAX;
	int left, right;
	for (int k = i; k < j; k++) {
		if (dp[i][k] != -1) {
			left = dp[i][k];
		} else {
			left = minPalPartition(s, i, k);
			dp[i][k] = left;
		}
		if (dp[k + 1][j] != -1) {
			right = dp[k + 1][j];
		} else {
			right = minPalPartition(s, k + 1, j);
			dp[k + 1][j] = right;
		}
		temp = left + right + 1;
		ans = min(ans, temp);
	}
	return dp[i][j] = ans;
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
		string str;
		cin >> str;

		memset(dp, -1, sizeof(dp));
		cout << minPalPartition(str, 0, str.size() - 1) << "\n";
		
	}
}			
