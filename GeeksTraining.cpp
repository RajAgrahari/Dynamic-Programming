//https://practice.geeksforgeeks.org/problems/geeks-training/1
int maximumPoints(vector<vector<int>>& points, int n) {
        int dp[n][3] = {0};
        for(int j=0;j<3;j++)
        dp[n-1][j] = points[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<3;j++)
            {
                int mx=INT_MIN;
                for(int k=0;k<3;k++)
                {
                    if(j!=k)
                    mx=max(mx,dp[i+1][k]);
                }
                dp[i][j] = points[i][j]+mx;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<3;i++)
        ans = max(ans,dp[0][i]);
        return ans;
    }
