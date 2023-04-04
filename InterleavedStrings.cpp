//https://practice.geeksforgeeks.org/problems/interleaved-strings/1
bool helper(int i,int j,int k,string A,string B,string C,vector<vector<vector<int>>>&dp)
    {
        if(k==C.size())
        return true;
        
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        
        bool pick=false,pick2=false;
        if(i<A.size() && A[i]==C[k])
        pick = helper(i+1,j,k+1,A,B,C,dp);
        if(j<B.size() && B[j]==C[k])
        pick2 = helper(i,j+1,k+1,A,B,C,dp);
        return dp[i][j][k] = (pick || pick2);
    }
    bool isInterleave(string A, string B, string C) 
    {
          int n = A.size();
          int m = B.size();
          int p = C.size();
          if(p!=(n+m))
          return false;
        
          vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(p+1,-1)));
          return helper(0,0,0,A,B,C,dp);
    }
