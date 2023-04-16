//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
int helper(int i,int j,int k,vector<vector<int>>& piles,vector<vector<vector<int>>>& dp)
    {
        if(i==piles.size() || k==0 || j==piles[i].size())
        return 0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int notpick = helper(i+1,0,k,piles,dp);
        int pick = max(piles[i][j]+helper(i+1,0,k-1,piles,dp),piles[i][j]+helper(i,j+1,k-1,piles,dp));
        return dp[i][j][k] = max(pick,notpick);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        int n = piles.size();
        int m;
        for(int i=0;i<n;i++)
        {
            int temp = piles[i].size();
            m = max(m,temp);
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return helper(0,0,k,piles,dp);
    }
