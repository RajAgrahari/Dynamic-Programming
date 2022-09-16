int DivisibleByM(vector<int>nums, int m){
		    int n = nums.size();
		    int sum=0;
		    for(int i=0;i<n;i++)
		    sum+=nums[i];
		   bool dp[n+1][sum+1];
		   for(int i=0;i<=n;i++)
		   {
		      for(int j=0;j<=sum;j++)
		      {
		          if(i==0 && j==0)
		          dp[i][j]=true;
		          else if(i==0)
		          dp[i][j]=false;
		          else if(nums[i-1]<=j)
		          dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
		          else
		          dp[i][j]=dp[i-1][j];
		      }
		   }
		   for(int i=1;i<=n;i++)
		   {
		      for(int j=m;j<=sum;j+=m)
		      {
		         if(dp[i][j]==true)
		         return 1;
		          
		      }
		   }
		   return 0;
		}