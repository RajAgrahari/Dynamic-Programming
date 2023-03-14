//https://practice.geeksforgeeks.org/problems/7ae455e552dc4e07f76bbe2adc4d4207ce1ff16e/1
         int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp)
        {
             if(i>j)
             return 0;
             int ans = INT_MIN;
             if(dp[i][j] != -1)
             return dp[i][j];
             for(int k=i;k<=j;k++)
             {
                int cost = nums[i-1]*nums[k]*nums[j+1] + helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
                ans = max(ans,cost);
             }
             return dp[i][j] = ans;
        }
         int maxCoins(int N, vector<int>& nums)
        {
             int n = nums.size();
            nums.push_back(1);
            nums.insert(nums.begin(),1);
            vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
            return helper(1,n,nums,dp);
        }
