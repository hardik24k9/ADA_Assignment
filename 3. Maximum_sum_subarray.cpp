#include <bits/stdc++.h>
using namespace std;

// Greedy Approach

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        
        int n=nums.size();
        int sum=0,ans=nums[0];
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};

// DP Approach

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        
        int n=nums.size();
        int dp[100001],ans=INT_MIN;
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            dp[i] = max(dp[i-1],0) + nums[i-1];
            ans = max(dp[i],ans);
        }
        return ans;
    }
};