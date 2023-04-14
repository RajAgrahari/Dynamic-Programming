//https://leetcode.com/problems/super-washing-machines/description/
int findMinMoves(vector<int>& machines) 
    {
        int n = machines.size();
        int sum=0;
        for (int i = 0; i < n; ++i)
        sum+= machines[i];

        if(sum%n) 
        return -1;

        int avg = sum/n;
        int res = 0,cursum=0;
        for (int i=0;i<n;++i)
        {
            cursum += (avg - machines[i]);
            res = max(res,max(abs(cursum),machines[i]-avg));
        }
        return res;
    }
