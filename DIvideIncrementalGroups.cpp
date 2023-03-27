//https://practice.geeksforgeeks.org/problems/c239059f6d110e6778cc2f2a1ab58ffd0a3d64ca/1
int helper(int i,int sum,int k,int numToBeSub[],int N,vector<vector<vector<int>>>& dp)
    {
        if(i==N)
        return 0;
        if(k<0 || sum<0)
        return 0;
        if(k==0 && sum!=0)
        return 0;
        if(k==0 && sum==0)
        return 1;
        if(dp[i][sum][k]!=-1)
        return dp[i][sum][k];
        int pick = 0;
        if(numToBeSub[i]<=sum)
        pick = helper(i,sum-numToBeSub[i],k-1,numToBeSub,N,dp);
        int not_pick = helper(i+1,sum,k,numToBeSub,N,dp);
        return dp[i][sum][k] = pick+not_pick;
        
    }
    int countWaystoDivide(int N, int k) 
    {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N+1,vector<int>(k+1,-1)));
        int numToBeSub[N];
        for(int i=1;i<=N;i++)
        {
            numToBeSub[i-1] = i;
        }
        int sum=N;
        return helper(0,sum,k,numToBeSub,N,dp);
    }
