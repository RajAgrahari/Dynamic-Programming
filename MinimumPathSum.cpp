//https://leetcode.com/problems/minimum-path-sum/
int helper(int n,int m,vector<vector<int>>& dp,vector<vector<int>>& grid)
    {
        if(n==0 && m==0)
        return grid[n][m];
        if(n<0 || m<0)
        return INT_MAX;
        if(dp[n][m]!=-1)
        return dp[n][m];
        int left = helper(n,m-1,dp,grid);
        int up = helper(n-1,m,dp,grid);
        
        return dp[n][m] = grid[n][m]+min(left,up);
        
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,dp,grid);
    }
