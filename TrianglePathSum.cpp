//https://practice.geeksforgeeks.org/problems/triangle-path-sum/1
int helper(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
         if(i==n-1)
         return triangle[i][j];
         if(dp[i][j]!=-1)
         return dp[i][j];
         int down = helper(i+1,j,n,triangle,dp);
         int down_right = helper(i+1,j+1,n,triangle,dp);
         return dp[i][j] = triangle[i][j]+min(down,down_right);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int j=0;j<n;j++)
        dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                dp[i][j] = triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
    }
