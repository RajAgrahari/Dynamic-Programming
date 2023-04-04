//https://practice.geeksforgeeks.org/problems/word-break1352/1
bool helper(int i,string temp,string A,unordered_map<string,int>& mp)
    {
        if(i==A.size())
        {
            if(temp=="")
            return true;
            return false;
        }
        temp += A[i];
        if(mp[temp]>0)
        return helper(i+1,"",A,mp) || helper(i+1,temp,A,mp);
        else
        return helper(i+1,temp,A,mp);
    }
    int wordBreak(string A, vector<string> &B) 
    {
        unordered_map<string,int> mp;
        for(int i=0;i<B.size();i++)
        mp[B[i]]++;
        string temp = "";
        return helper(0,temp,A,mp);
    }
