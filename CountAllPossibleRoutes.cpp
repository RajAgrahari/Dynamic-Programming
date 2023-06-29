//https://leetcode.com/problems/count-all-possible-routes/description/
int helper(vector<int>& locations, int cur, int finish, int rem,
              vector<vector<int>>& dp) {
        if (rem < 0) {
            return 0;
        }
        if (dp[cur][rem] != -1) {
            return dp[cur][rem];
        }

        int ans = cur == finish ? 1 : 0;
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != cur) {
                ans = (ans + helper(locations, nextCity, finish,
                                   rem - abs(locations[cur] - locations[nextCity]),
                                   dp)) % 1000000007;
            }
        }

        return dp[cur][rem] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
              int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));

        return helper(locations, start, finish, fuel,dp);
    }
