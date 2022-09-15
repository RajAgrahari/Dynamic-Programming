#include<bits/stdc++.h>
using namespace std;
int mD(string s1, int m, string s2, int n){
        if(m==0){
            return n;   /// insert all of s2
        }
        if(n==0){
            return m;    /// del all of s1
        }
        
        if(s1[m-1] == s2[n-1]){
            return mD(s1,m-1,s2,n-1);
        }
        int insert = mD(s1,m,s2,n-1);
        int del = mD(s1,m-1,s2,n);
        int replace = mD(s1,m-1,s2,n-1);
        return 1 + min(insert , min(del,replace));
        
    }
int minDistance(string s1, string s2) {
        return mD(s1, s1.size(), s2, s2.size());
}
int minDistance2(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
            dp[i][j]=j;   /// insert all of s2
            else if(j==0)
            dp[i][j]=i;    /// del all of s1
            else if(s1[i-1]==s2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            {
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace  = dp[i-1][j-1];
                dp[i][j] = 1+ min(insert,min(del,replace));
                //Simply we can write this: dp[i][j] = 1+ min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }

        }
    }
    return dp[m][n];

}
int main()
{
    cout<<minDistance("horse","ros")<<endl;
    cout<<minDistance2("horse","ros")<<endl;
    return 0;
}