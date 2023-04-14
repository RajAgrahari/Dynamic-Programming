//https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/
vector<long long> maximumEvenSplit(long long finalSum) 
    {
        if(finalSum&1)
        return {};
        long long int x = 2,sum=0;
        vector<long long int> ans;
        while(sum+x<=finalSum)
        {
            sum += x;
            ans.push_back(x);
            x += 2;
        }
        ans.back()+=(finalSum-sum);
        return ans;
    }
