//Climb the stairs
#include<bits/stdc++.h>
using namespace std;
int helper(int* arr,int n)
{
   if(n==0 || n==1)
    return 1;
    if(arr[n]!=0)
    return arr[n];
    return helper(arr,n-2) + helper(arr,n-1);
}
//Top->down DP,we can only take 1 step or 2 step to reach nth step
int climbTheStairs(int n)
{
    int* a = new int[n+1];
    for(int i=0;i<=n;i++)
    a[i]=0;
    return helper(a,n);

}
//Down->top DP,we can only take 1 step or 2 step to reach nth step;
int climbTheStairs2(int n)
{
    int* dp = new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//Down->top DP,we can only take upto k-steps i.e. 1,2,3,4.... to reach nth step
int climbTheStairs3(int n,int k)
{
    int* dp = new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            ans+=dp[i-j];
        }
        dp[i]=ans;
    }
    return dp[n];
}
int main()
{
    cout<<climbTheStairs(10)<<endl;
    cout<<climbTheStairs2(10)<<endl;
    cout<<climbTheStairs3(10,2)<<endl;
    return 0;
}