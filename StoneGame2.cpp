//https://leetcode.com/problems/stone-game-ii/
int helper(int i,int m,int n,vector<int>& piles,vector<vector<int>>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[m][i] != -1) {
            return dp[m][i];
        }
        int alice = 0;
        int ans = INT_MIN;
        for(int j=0;j<2*m && (i+j)<n;j++)
        {
            alice += piles[i+j];
            ans = max(ans,alice-helper(i+j+1,max(m,j+1),n,piles,dp));
        }
        return dp[m][i] = ans;
    }
    int stoneGameII(vector<int>& piles)
    {
        int n = piles.size();
         vector<vector<int>> dp(2*n, vector<int>(n,-1));
         int tot = 0;
         for(auto x:piles)
         tot += x;
         int d = helper(0,1,n,piles,dp); // alice-bob+alice-bob......
         int alice2 = (tot+d);//2*(alice+alice+alice....)
         return alice2/2;

    }
