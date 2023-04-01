//https://practice.geeksforgeeks.org/problems/chocolates-pickup/1
int helper(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int i,int j1,int j2,int n)
    {
        if(i>=n || j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
        return 0;
        if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        if(i==n-1)
        {
            if(j1==j2)
            dp[n-1][j1][j2]=grid[n-1][j1];
            else
            dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
        int maxi = INT_MIN;
        for(int r1 =-1;r1<=1;r1++){ 
            for(int r2 = -1;r2<=1;r2++){
            int ans=0;
                if(j1!=j2){
                    
                    ans=grid[i][j1]+grid[i][j2]+helper(grid,dp,i+1,j1+r1,j2+r2,n);
                }
                else{
                    ans= grid[i][j1]+helper(grid,dp,i+1,j1+r1,j2+r2,n);
                }
                maxi = max(ans,maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
       
    int solve(int n, int m, vector<vector<int>>& grid) 
    {
          vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
          return helper(grid,dp,0,0,m-1,n);
    }
