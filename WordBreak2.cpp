//https://leetcode.com/problems/word-break-ii/description/
void helper(int l,int n,string& s,vector<string>& wordDict,unordered_map<string,int>& mp,vector<string>& ans,vector<string>& temp)
    {
         if(l==n)
         {
            string x;
            for(int p=0;p<temp.size()-1;p++)
            x += (temp[p]+" ");
            x += temp[temp.size()-1];
            ans.push_back(x);
            return;
         }
         
         for(int i=l;i<n;i++)
         {
             if(mp.count(s.substr(l,i-l+1)))
             {
                temp.push_back(s.substr(l,i-l+1));
                helper(i+1,n,s,wordDict,mp,ans,temp);
                temp.pop_back();
             }
         }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        unordered_map<string,int> mp;
        vector<string> ans;
        vector<string> temp;

        for(string it:wordDict)
        mp[it]++;
        helper(0,n,s,wordDict,mp,ans,temp);
        return ans;
    }
