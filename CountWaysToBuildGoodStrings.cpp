//https://leetcode.com/problems/count-ways-to-build-good-strings/description/
int mod = 1000000007;
    int helper(int cur,int low,int high,int zero,int one,vector<int>& dp)
    {
        if(cur>high)
        return 0;
        if(dp[cur]!=-1)
        return dp[cur];
        int ans = 0;
        if(low<=cur && cur<=high)
        ans = (1 + helper(cur+zero,low,high,zero,one,dp) + helper(cur+one,low,high,zero,one,dp))%mod;
        else
        ans = (helper(cur+zero,low,high,zero,one,dp) + helper(cur+one,low,high,zero,one,dp))%mod;
        return dp[cur] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> dp(high+1,-1);
        return helper(0,low,high,zero,one,dp);
    }
