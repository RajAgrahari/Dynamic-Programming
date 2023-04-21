//https://leetcode.com/problems/profitable-schemes/description/
int mod = 1000000007;
    int dp[101][101][101]={-1};
    int helper(int& n,int i,int p,int g,int& mp,vector<int>& group,vector<int>& profit)
    {
        if(g>n)
        return 0;
        if(i==profit.size())
        return p>=mp;
        if(dp[i][p][g]!=-1)
        return dp[i][p][g];
        int nottake = helper(n,i+1,p,g,mp,group,profit)%mod;
        int take=helper(n,i+1,min(mp,p+profit[i]),g+group[i],mp,group,profit)%mod;
        return dp[i][p][g] = (nottake+take)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        // int mx = (*max_element(profit.begin(),profit.end()))*(profit.size());
        int m = profit.size();
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(mx,vector<int>(n+1,-1)));
        memset(dp,-1,sizeof(dp));
        return helper(n,0,0,0,minProfit,group,profit);
    }
