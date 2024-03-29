//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/
long long MOD = 1000000007;
    int solve(vector<vector<int>>&freq, string& target, vector<vector<int>>& dp, int colIdx, int targetIdx)
    {
        
        if (targetIdx == target.size()) 
        return 1; 
        if (colIdx == freq.size()) 
        return 0;  

        if (dp[colIdx][targetIdx] != -1) 
        return dp[colIdx][targetIdx];
        char targetCh = target[targetIdx];
        int notPickWays = solve(freq, target, dp, colIdx + 1, targetIdx);
        
        int pickWays = 0;
        if (freq[colIdx][targetCh - 'a'] != 0)
        {
            int currWays = freq[colIdx][targetCh - 'a'];
            int nextWays = solve(freq, target, dp, colIdx + 1, targetIdx + 1);
            pickWays = (currWays * (long long)nextWays) % MOD;
        }
        
        return dp[colIdx][targetIdx] = ((pickWays + (long long)notPickWays) % MOD);
        
    }
    int numWays(vector<string>& words, string target) 
    {
        int m = words.size(), n = words[0].size();
        vector<vector<int>>freq(n, vector<int>(26, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch = words[i][j];
                freq[j][ch - 'a']++; //freq of 'ch' in jth col
            }
        }
        vector<vector<int>>dp(n, vector<int>(target.size(), -1));
        int ans = solve(freq, target, dp, 0, 0);
        return ans;
    }
