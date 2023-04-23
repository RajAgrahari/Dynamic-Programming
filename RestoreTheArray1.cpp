//https://leetcode.com/problems/restore-the-array/description/
    int mod = 1000000007;
    int helper(int l,int n,string& s,string& temp,vector<int>& dp)
    {
        if(l==n)
        return 1;
        if(s[l]=='0')
        return 0;
        if(dp[l]!=-1)
        return dp[l];
        int cnt = 0;
        for(int i=l;i<l+temp.size() && i<n;i++)
        {
            string x = s.substr(l,i-l+1);
            if(x.size()<temp.size() || (x.size()==temp.size() && x <= temp))
            {
               cnt = (cnt+helper(i+1,n,s,temp,dp))%mod;
            }
        }
        return dp[l] = cnt;
    }
    int numberOfArrays(string s, int k) 
    {
        int n = s.size();
        string temp = to_string(k);
        vector<int> dp(n,-1);
        return helper(0,n,s,temp,dp);
    }
