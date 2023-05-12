//https://leetcode.com/problems/solving-questions-with-brainpower/
long long helper(vector<vector<int>>& questions,int i,int n,vector<long long>& dp)
    {
         if(i>=n)
         return 0;
         if(dp[i]!=-1)
         return dp[i];
         long long not_take = helper(questions,i+1,n,dp);
         long long take = questions[i][0] + helper(questions,i+questions[i][1]+1,n,dp);
         return dp[i] = max(not_take,take);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return helper(questions,0,n,dp);
    }
