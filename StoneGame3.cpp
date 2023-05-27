//https://leetcode.com/problems/stone-game-iii/description/
int helper(int i,int n,vector<int>& stoneValue,vector<int>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int alice = 0,ans = INT_MIN;
        for(int k=i;k<i+3 && k<n;k++)
        {
             alice += stoneValue[k];
             ans = max(ans,alice-helper(k+1,n,stoneValue,dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
         vector<int> dp(n+1,-1);
         int sum = 0;
         for(int x:stoneValue)
         sum += x;
         int d = helper(0,n,stoneValue,dp);
         int alice = (sum+d)/2;
         int bob = (sum-alice);
         if(alice == bob)
         return "Tie";
         else if(alice>bob)
         return "Alice";
         return "Bob";
    }
