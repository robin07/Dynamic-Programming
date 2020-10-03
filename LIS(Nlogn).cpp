							LONGEST INCREASING SUBSEQUENCE(NLOGN)
							
Ques:-	Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output:
6

Code:-

#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> v){
    int n=v.size();
    
    vector<int> larr;
    larr.push_back(v[0]);
    
    for(int i=0;i<n;i++){
        if(larr.back()<v[i]){
            larr.push_back(v[i]);
        }else{
            int idx=lower_bound(larr.begin(),larr.end(),v[i])-larr.begin();
            larr[idx]=v[i];
        }
    }
    return larr.size();
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> v;
        
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v.push_back(a);
        }
        
        cout<<lis(v)<<"\n";
    }
}
