//https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
int dp[2001][2001]={-1};
    int lcs(string &s, int i, int j,int n,int m,int& ans)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            dp[i][j]=2+lcs(s,i+1,j-1,n,m,ans);
            if(i<n && j>=n)
            ans = max(ans,dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j]=max(lcs(s,i+1,j,n,m,ans),lcs(s,i,j-1,n,m,ans));
    }
    int longestPalindrome(string s1, string s2)
    {
       
        lcs(s,0,n-1,n1,n2,ans);
        return ans;
        
    }
