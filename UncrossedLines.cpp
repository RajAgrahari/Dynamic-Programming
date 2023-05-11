//https://leetcode.com/problems/uncrossed-lines/
 int helper(int i,int j,int n,int m,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp)
    {
        if(i>=n || j>=m)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(nums1[i]==nums2[j])
        return dp[i][j] = 1+helper(i+1,j+1,n,m,nums1,nums2,dp);
        return dp[i][j] = max(helper(i+1,j,n,m,nums1,nums2,dp),helper(i,j+1,n,m,nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,nums1,nums2,dp);
    }
