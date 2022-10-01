// https://leetcode.com/problems/longest-string-chain/
bool compareString(string s,string t)
    {
        if(s.size()!=t.size()+1)
            return false;
        int first = 0;
        int second = 0;
        while(first<s.size())
        {
            if(s[first]==t[second])
            {
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s.size() && second==t.size())
        return true;
        return false;
    }
    static bool cmp(string s,string t)
    {
        return s.size()<t.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),cmp);
           int ma=1;
          for(int i=0;i<words.size();i++)
          {
              for(int prev=0;prev<i;prev++)
              {
                  if(compareString(words[i],words[prev]) && 1+dp[prev]>dp[i])
                  {
                      dp[i] = 1 + dp[prev];
                  }
              }
              if(ma<dp[i])
              {
                  ma=dp[i];
              }
                  
          }
        return ma;
    }