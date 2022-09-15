#include<bits/stdc++.h>
using namespace std;
int knapSack(int* weight,int* prices,int n,int w)
{
   if(w==0 || n==0)
   return 0;
   if(w<weight[n-1])
   return knapSack(weight,prices,n-1,w);
   return max(prices[n-1] + knapSack(weight,prices,n-1,w-weight[n-1]),knapSack(weight,prices,n-1,w));

}

//Time: O(N*W) Space: O(N*W)
int knapSack2(int* weight,int* prices,int n,int w){
    if(w==0 || n==0)
    return 0;
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
           if(i==0 || j==0)
             dp[i][j]=0;
           else if(j<weight[i-1])
             dp[i][j]=dp[i-1][j];
           else
             dp[i][j]=max(prices[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][w];
}
int main()
{
    int weight[] = {3,4,7,2,5};
    int prices[] = {1,2,3,4,5};
    cout<<knapSack(weight,prices,5,10)<<endl;
    cout<<knapSack2(weight,prices,5,10)<<endl;
    return 0;
}