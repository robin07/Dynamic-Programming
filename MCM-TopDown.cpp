							MATRIX CHAIN MULTIPLICATION
							
Ques:-Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000

Explanation:-There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
  
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


int MCMcost(int arr[], int start, int end) {
	if (start >= end) {
		return 0;
	}
	if (dp[start][end] != -1) {
		return dp[start][end];
	}
	int mn = INT_MAX, temp;
	for (int k = start; k < end; k++) {
		temp = MCMcost(arr, start, k) + MCMcost(arr, k + 1, end) + (arr[start - 1] * arr[k] * arr[end]);
		if (temp < mn) {
			mn = temp;
		}
	}
	dp[start][end] = mn;
	return dp[start][end];
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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << MCMcost(arr, 1, n - 1) << "\n";
	}
}
