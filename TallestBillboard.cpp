//https://leetcode.com/problems/tallest-billboard/description/
int dp[21][10001];
    int helper(int i,int n,int sum,vector<int>& rods)
    {
        if(i == n)
        {
            if(sum==0)
            return 0;
            return INT_MIN;
        }
        if(dp[i][sum+5000]!=-1)
        return dp[i][sum+5000];
        int skip = helper(i+1,n,sum,rods);
        int pick1 = rods[i]+helper(i+1,n,sum+rods[i], rods);
        int pick2 = helper(i+1,n,sum-rods[i], rods);
        return dp[i][sum+5000]=max(pick1,max(pick2,skip));
    }
    int tallestBillboard(vector<int>& rods)
    {
        int ans = 0;
        int n = rods.size();
        memset(dp,-1,sizeof(dp));
        // vector<vector<int>> dp(n + 1, vector<int>(10001, -1));
        return helper(0,n,0,rods); 
    }
