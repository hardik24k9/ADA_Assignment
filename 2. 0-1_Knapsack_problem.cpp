#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 
// Time Complexity :- O(N*W)
// Space Complexity :- O(N*W)

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1001][1001];
    
    int solve(int wt[],int val[],int n,int w)
    {
        if(n==-1 or w==0) return 0;
        
        if(dp[n][w] != -1) return dp[n][w];
        
        if(wt[n] <= w)
        {
            int op1 = val[n] + solve(wt,val,n-1,w-wt[n]);
            int op2 = solve(wt,val,n-1,w);
            return dp[n][w] = max(op1,op2);
        }
        else
        {
            return dp[n][w] = solve(wt,val,n-1,w);
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof dp);
        return solve(wt,val,n-1,W);
    }
};