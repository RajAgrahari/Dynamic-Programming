//0<=nums[i]<=1000
 int countSubsetsWithGivenDiff(vector<int>& nums, int target) {
          int n = nums.size();
          int sum=0,count0=0;
          for(int i=0;i<n;i++)
          {
             sum+=nums[i];
             if(nums[i]==0)
              count0++;
          }  
          int x = (sum+target)/2;
          if((sum-target)%2==1 || sum<target)
              return 0;
          if(x<0)
              return 0;
          int dp[n+1][x+1];
          for(int i=0;i<=n;i++)
          {
              for(int j=0;j<=x;j++)
              {
                  if(i==0 && j==0)
                      dp[i][j]=1;
                  else if(i==0)
                      dp[i][j]=0;
                  else if(j==0)
                      dp[i][j]=1;
                  else if(nums[i-1]<=j && nums[i-1]!=0)
                      dp[i][j]=dp[i-1][j-nums[i-1]] + dp[i-1][j];
                  else
                      dp[i][j]=dp[i-1][j];
              }
          }
          return   pow(2,count0)*dp[n][x];
 }
 
        