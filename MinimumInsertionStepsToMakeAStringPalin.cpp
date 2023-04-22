//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
int helper(int i,int j,string& s,vector<vector<int>>& dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==s[j])
        return dp[i][j] = helper(i+1,j-1,s,dp);
        else
        return dp[i][j] = 1 + min(helper(i+1,j,s,dp),helper(i,j-1,s,dp));
    }
    int minInsertions(string s) {
        int m = s.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return helper(0,m-1,s,dp);
    }
