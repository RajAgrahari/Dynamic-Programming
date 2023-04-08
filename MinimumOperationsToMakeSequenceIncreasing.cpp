//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
int minSwap(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int dp[n][2];
        for(int i=0;i<n;i++)
        {
            dp[i][0]=INT_MAX; dp[i][1]=INT_MAX;
        }
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++)
        {
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i])
            {
                dp[i][1] = 1+dp[i-1][1];
                dp[i][0] = dp[i-1][0];
            }
            if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i])
            {
                dp[i][1] = min(dp[i][1],1+dp[i-1][0]);
                dp[i][0] = min(dp[i][0],dp[i-1][1]);
            }
        }
        return min(dp[n-1][1],dp[n-1][0]);
    }
