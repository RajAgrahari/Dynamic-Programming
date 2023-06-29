//https://leetcode.com/problems/count-number-of-texts/description/
int mod = 1000000007;
    int helper(int i,int n,string& s,vector<int>& dp)
    {
        if(i==n)
        return 1;
        if(i>n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        long long cnt=0;
        int f=1,idx=i;
        int mxf = (s[i]=='7' || s[i]=='9')?4:3;
        while(f<=mxf && idx<n && s[idx]==s[i])
        {
            idx++;
            f++;
            cnt = (cnt+helper(idx,n,s,dp))%mod;
        }
        return dp[i] = (cnt%mod);

    }
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return helper(0,n,s,dp);
    }
