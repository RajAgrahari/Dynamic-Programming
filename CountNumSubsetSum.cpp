int perfectSum(int arr[], int n, int sum)
	{
	    long long m =1e9 + 7;
        int dp[n+1][sum+1];	
        memset(dp,0,sizeof(dp));
        
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0 && j==0)
	            dp[i][j]=1;
	            else if(i==0)
	            dp[i][j]=0;
	            else if(arr[i-1]<=j)
	            dp[i][j]=((dp[i-1][j-arr[i-1]])%m+(dp[i-1][j])%m)%m;
	            else
	            dp[i][j]=(dp[i-1][j])%m;
	        }
	    }
	    return (dp[n][sum])%m;
	}