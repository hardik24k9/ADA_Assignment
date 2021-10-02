#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 
// Time Complexity :- O(N*M)
// Space Complexity :- O(N*M)

class Solution
{
  public:
  
    long long int dp[1001][1001];
    
    long long int solve(int S[],int m,int n)
    {
        if(m==-1 and n>0) return 0;
        
        if(n==0) return 1;
        
        if(n<0)  return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        return dp[m][n] = solve(S,m,n-S[m]) + solve(S,m-1,n);
    }
  
    long long int count( int S[], int m, int n )
    {
        memset(dp,-1,sizeof dp);
        long long int ans = solve(S,m-1,n);
        return ans;
    }
};

// Approach :- 2
// Time Complexity :- O(N*M)
// Space Complexity :- O(N)

class Solution
{
  public:
  
    long long int count( int S[], int m, int n )
    {
        long long int dp[n+1];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=S[i];j<=n;j++)
            {
                dp[j] += dp[j-S[i]];
            }
        }
        
        return dp[n];
    }
};