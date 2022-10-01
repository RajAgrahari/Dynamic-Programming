//longest increasing subarray
//https://leetcode.com/problems/longest-continuous-increasing-subsequence/
int findLengthOfLCIS(vector<int>& nums) {
        int count=1,ma=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
                count++;
            else
             {   ma=max(ma,count);
                count=1;
             }
        }
        ma=max(ma,count);
        return ma;
    }

//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
int longestSubsequence(int n, int a[])
    {
        set<int> s;
        vector<int> b;
        set<int>::iterator itr;
        
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        
        
        for(itr=s.begin();itr!=s.end();itr++)
        {
            b.push_back(*itr);
        }
        int m = b.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

// Iterative way of finding longest incresing subsequence
int longestSubsequence(int n, int a[])
{
        vector<int> dp(nums.size(),1);
           int ma=1;
          for(int i=0;i<nums.size();i++)
          {
              for(int prev=0;prev<i;prev++)
              {
                  if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
                  {
                      dp[i] = 1 + dp[prev];
                  }
              }
              if(ma<dp[i])
              {
                  ma=dp[i];
              }
                  
          }
        return ma;
       
}