//https://leetcode.com/problems/word-break/description/
bool helper(int l,int n,string& s,vector<string>& wordDict,unordered_map<string,int>& mp,int dp[])
    {
         if(l==n)
         return true;
         if(dp[l]!=-1)
         return dp[l];
         bool f = false;
         for(int i=l;i<n;i++)
         {
             if(mp.count(s.substr(l,i-l+1)))
             {
                f |= helper(i+1,n,s,wordDict,mp,dp);
             }
         }
         return dp[l] = f;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        unordered_map<string,int> mp;
        for(string it:wordDict)
        mp[it]++;
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return helper(0,n,s,wordDict,mp,dp);
    }
