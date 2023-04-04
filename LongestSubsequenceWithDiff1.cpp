//https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
int helper(vector<vector<int>>& dp,int i,int n,int A[],int prev)
    {
        if(i==n)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        if(prev==-1 || abs(A[i]-A[prev])==1)
        return dp[i][prev+1]=max(1+helper(dp,i+1,n,A,i),helper(dp,i+1,n,A,prev));
        else
        return dp[i][prev+1]=helper(dp,i+1,n,A,prev);
    }
    int longestSubsequence(int N, int A[])
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        int prev=-1;
        return helper(dp,0,N,A,prev);
    }
