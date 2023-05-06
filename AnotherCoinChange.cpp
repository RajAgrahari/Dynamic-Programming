//https://practice.geeksforgeeks.org/problems/09b910559335521654aa2909f86f893447d8f5ba/1
int helper(int i,int cnt,int target,int k,int n,vector<int>& coins,vector<vector<vector<int>>>& dp)
    {
        
        if(cnt==k && target==0)
        return 1;
        if(cnt>=k || target<=0)
        return 0;
        if(i>=n)
        return 0;
        if(dp[i][target][cnt]!=-1)
        return dp[i][target][cnt];
        int nottake = helper(i+1,cnt,target,k,n,coins,dp);
        int take=false;
        if(coins[i]<=target)
        take = helper(i,cnt+1,target-coins[i],k,n,coins,dp);
        
        return dp[i][target][cnt] = (nottake || take);
        
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) 
    {
       vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(target+1,vector<int>(K+1,-1)));
       return helper(0,0,target,K,N,coins,dp)==1?true:false;
    }
