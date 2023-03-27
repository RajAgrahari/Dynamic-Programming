//https://leetcode.com/problems/minimum-path-cost-in-a-grid/
int helper(int x,int y,int n,int m,vector<vector<int>>& movecost,vector<vector<int>>& dp,vector<vector<int>>& grid)
    {
        if(x>=n || y>=m)
        return INT_MAX;
        if(dp[x][y]!=-1)
        return dp[x][y];
        int ans = INT_MAX;
        if(x==n-1)
        {
            return dp[x][y] = grid[x][y];
        }
        for(int j=0;j<m;j++)
        {
            ans = min(ans,movecost[grid[x][y]][j]+grid[x][y]+helper(x+1,j,n,m,movecost,dp,grid));
        }
        return dp[x][y] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& movecost) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MAX;
        for(int j=0;j<m;j++)
        {
            ans = min(ans,helper(0,j,n,m,movecost,dp,grid));
        }
        return ans;
    }
