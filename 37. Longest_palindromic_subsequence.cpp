#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N)
// Space Complexity :- O(N*N)

int dp[1001][1001];

int solve(int i,int j,string s)
{
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j] = 2 + solve(i+1,j-1,s);
    else return dp[i][j] = max(solve(i+1,j,s),solve(i,j-1,s));
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,n-1,s);
    cout << ans << endl;
}