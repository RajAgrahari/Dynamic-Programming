
int longestSubsequence(int n, int a[])
{
       vector<int> hash(nums.size());
        vector<int> dp(nums.size(),1);
            sort(nums.begin(),nums.end());
           int ma=1,idx=0;
          for(int i=0;i<nums.size();i++)
          {
              hash[i]=i;
              for(int prev=0;prev<i;prev++)
              {
                  if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
                  {
                      dp[i] = 1 + dp[prev];
                      hash[i] = prev;
                  }
              }
              if(ma<dp[i])
              {
                  ma=dp[i];
                  idx=i;
              }
                  
          }
          vector<int> ans;
          ans.push_back(nums[idx]);
        while(hash[idx]!=idx)
        {
            idx = hash[idx];
            ans.push_back(nums[idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }