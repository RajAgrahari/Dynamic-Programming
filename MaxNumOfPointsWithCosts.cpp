long long maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        int m = points[0].size();
        vector<long long> prev(m);
        for(int i=0;i<m;i++)
        prev[i] = points[0][i];
        for(int i=0;i<n-1;i++)
        {
            vector<long long> leftmax(m);
            vector<long long> rightmax(m);
            vector<long long> cur(m);
            leftmax[0] = prev[0];
            for(int j=1;j<m;j++)
            {
                leftmax[j] = max(leftmax[j-1]-1,prev[j]);
            }
            rightmax[m-1] = prev[m-1];
            for(int j=m-2;j>=0;j--)
            {
                rightmax[j] = max(rightmax[j+1]-1,prev[j]);
            }
            for(int j=0;j<m;j++)
            {
                cur[j] = max(leftmax[j],rightmax[j])+points[i+1][j];
            }
            prev = cur;
        }

        long long ans = 0;
        for(int i=0;i<m;i++)
        ans = max(ans,prev[i]);
        return ans;
    }
