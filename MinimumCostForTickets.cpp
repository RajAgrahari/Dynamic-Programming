//https://leetcode.com/problems/minimum-cost-for-tickets/
int helper(int i,int n,vector<int>& days,vector<int>& costs,vector<int>& v,vector<int>& dp)
    {
        if(i>=days.size() || i>n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans = costs[0]+helper(i+1,n,days,costs,v,dp);
        ans = min(ans,costs[1]+helper(v[days[i]+7],n,days,costs,v,dp));
        ans = min(ans,costs[2]+helper(v[days[i]+30],n,days,costs,v,dp));
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> v(400,days.size());
        vector<int> dp(days.size()+1,-1);
        int n = days.size();
        sort(days.begin(),days.end());
        int j=1;
        for(int i=0;i<n;i++)
        {
            while(j<=days[n-1] && j<=days[i])
            {
               v[j] = i;
               j++;
            }
            if(j>days[n-1])
            break;
        }
        return helper(0,days[n-1],days,costs,v,dp);
    }
