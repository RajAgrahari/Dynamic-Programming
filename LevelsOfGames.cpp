//https://practice.geeksforgeeks.org/problems/levels-of-game/1
        int helper(int prev,int h,int m,vector<vector<vector<int>>>& dp)
        {
            if(h<=0 || m<=0)
            return 0;
            if(dp[h][m][prev+1]!=-1)
            return dp[h][m][prev+1];
            if(prev==-1)
            {
                return dp[h][m][prev+1] = 1 + max(helper(0,h-20,m+5,dp),max(helper(1,h-5,m-10,dp),helper(2,h+3,m+2,dp)));
            }
            int mx;
            if(prev==0)
            {
                mx = 1 + max(helper(1,h-5,m-10,dp),helper(2,h+3,m+2,dp));
            }
            else if(prev==1)
            {
                mx = 1 + max(helper(0,h-20,m+5,dp),helper(2,h+3,m+2,dp));
            }
            else if(prev==2)
            {
                mx = 1 + max(helper(0,h-20,m+5,dp),helper(1,h-5,m-10,dp));
            }
            return dp[h][m][prev+1]=mx;
        }
        int maxLevel(int h,int m)
        {
            vector<vector<vector<int>>> dp(801,vector<vector<int>>(801,vector<int>(4,-1)));
            return helper(-1,h,m,dp)-1;
        }
