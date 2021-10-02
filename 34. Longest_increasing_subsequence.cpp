#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N) (Getting TLE)
// Space Complexity :- O(N) 

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n],ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

// Approach :- Using binary_search (Code library youtube)
// Time Complexity :- O(NLogN)
// Space Complexity :- O(N) 

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int dp[n+1],ans = 1;
        for(int i=1;i<=n;i++)
        {
            dp[i] = INT_MAX;
        }
        dp[0] = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int idx = upper_bound(dp,dp+n+1,a[i])-dp;
            if(a[i]>dp[idx-1] and a[i]<dp[idx])
            {
                dp[idx] = a[i];
                ans = max(idx,ans);
            }
        }
        
        return ans;
    }
};