//https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1
unordered_map<int,pair<int,int>> mp;
    vector<vector<long long>> dp;

    long long solve(int pos,int idx,vector<int>& temp,int dir)
    {
        if(idx==temp.size()) 
        return 0;

        if(dp[idx][dir]!=-1) 
        return dp[idx][dir];

        long long one=0,two=0;

        int left=mp[temp[idx]].first;

        int right=mp[temp[idx]].second;
        one=abs(pos-left)+abs(left-right)+solve(right,idx+1,temp,0);

        if(idx==temp.size()-1)
        {
            one+=abs(right-0);
        }
        two=abs(pos-right)+abs(right-left)+solve(left,idx+1,temp,1);

        if(idx==temp.size()-1)
        {
            two+=abs(left-0);

        }
        return dp[idx][dir]=min(one,two);

    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) 
    {
         mp.clear();

        int mx=*max_element(types.begin(),types.end());

        vector<int> ele(mx+1,0);

        for(int i=0;i<n;i++)
        {
            ele[types[i]]=1;

            if(mp.find(types[i])==mp.end())
            {
                mp[types[i]]={locations[i],locations[i]};

            }
            else{

                mp[types[i]]={min(locations[i],mp[types[i]].first),max(locations[i],mp[types[i]].second)};
            }

        }

        vector<int> temp;
        for(int i=0;i<=mx;i++)
        {
            if(ele[i])
            {
                temp.push_back(i);
            }
        }
        dp.resize(temp.size(),vector<long long>(2,-1));
        return solve(0,0,temp,0);
    }
