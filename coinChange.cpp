int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M+1][V+1];
	    for(int i=0;i<=M;i++)
        {
           for(int j=0;j<=V;j++)
           {
               if(i==0)
               dp[i][j]=INT_MAX-1;
               if(j==0)
               dp[i][j]=0;
           }
        }
        for(int j=0;j<=V;j++)
        {
            if(j%coins[0]==0)
            dp[1][j]=j/coins[0];
            else
            dp[1][j]=INT_MAX-1;
        }
	    for(int i=2;i<=M;i++)
        {
           for(int j=1;j<=V;j++)
           {
              if(coins[i-1]<=j)
              dp[i][j]= min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
              else
              dp[i][j]=dp[i-1][j];
           }
        }
        if(dp[M][V]==(INT_MAX-1))
        return -1;
        else
        return dp[M][V];
	} 