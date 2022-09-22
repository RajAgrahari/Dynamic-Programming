// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
cpp_int helper(vector<cpp_int>& dp,int n)
    {
        if(n<=1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        cpp_int res = 0;
        for(int i=0;i<n;i++)
        res += helper(dp,i)*helper(dp,n-i-1);
        return dp[n]=res;
    }

    cpp_int findCatalan(int n) 
    {
        vector<cpp_int> dp(n+1,-1);
        return helper(dp,n);
    }
