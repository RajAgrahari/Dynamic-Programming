//  https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 int findNumberOfLIS(vector<int>& nums) {
          vector<int> dp(nums.size(),1);
          vector<int> count(nums.size(),1);
         int ma=1;
          for(int i=0;i<nums.size();i++)
          {
              for(int prev=0;prev<i;prev++)
              {
                  if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
                  {
                      dp[i] = 1 + dp[prev];
                      count[i]=count[prev];
                  }
                  else if(dp[i]==(dp[prev]+1))
                  {
                      count[i]+=count[prev];
                  }
              }
             ma = max(ma,dp[i]);
                  
          }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==ma)
            ans += count[i];
        }
        return ans;
        
    }