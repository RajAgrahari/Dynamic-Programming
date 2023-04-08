//https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/
int longestNonDecreasingSubsequence(vector<int>& arr)
    {
        vector<int> sub;
        for (int i = 0; i < arr.size(); ++i) 
        {
            int x = arr[i];
            if (sub.empty() || sub[sub.size() - 1] <= x) 
            { 
                sub.push_back(x);
            } 
            else 
            {
                int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); 
                sub[idx] = x; 
            }
        }
        return sub.size();
    }
    int kIncreasing(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int ans=0;
        for(int i=0;i<k;i++)
        {
            vector<int> temp;
            for(int j=i;j<n;j+=k)
            temp.push_back(arr[j]);
            ans += temp.size()-longestNonDecreasingSubsequence(temp);
        }
        return ans;
    }
