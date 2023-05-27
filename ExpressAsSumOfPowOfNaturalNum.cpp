//https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
int mod = 1000000007;
    int helper(int i,int n,int x,vector<vector<int>>& dp)
    {
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        if(pow(i,x)>n)
        return 0;
        
        if(dp[i][n]!=-1)
        return dp[i][n];
        
        int nottake = helper(i+1,n,x,dp);
        int take=0;
        if((n-pow(i,x))>=0)
        {
            return take = helper(i+1,n-pow(i,x),x,dp);
        }
        return dp[i][n] = (take + nottake)%(int)1e9+7;
    }
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,x,dp);
    }
