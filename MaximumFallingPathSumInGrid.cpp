//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        memset(dp,0,sizeof(dp));
        
        for(int j=0;j<N;j++)
        dp[N-1][j]=Matrix[N-1][j];
        for(int i=N-2;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                int right = (j+1<N)?dp[i+1][j+1]:0;
                int down = dp[i+1][j];
                int diagonal = (j-1>=0)?dp[i+1][j-1]:0;
                dp[i][j]=Matrix[i][j]+max(diagonal,max(right,down));
            }
        }
        int ans=INT_MIN;
        for(int j=0;j<N;j++)
        {
            if(dp[0][j]>ans)
            ans=dp[0][j];
        }
        return ans;
    }
