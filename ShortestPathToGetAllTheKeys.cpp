//https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = { i, j, 0 }; 
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int cnt = 0; 

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) 
            {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                if (grid[row][col] == '#')
                    continue;

                if (isupper(grid[row][col]))
                {
                    if((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                    continue;
                }

                if (islower(grid[row][col])) 
                {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                if (form == form_end)
                    return cnt;

                if (dp[row][col][form])
                    continue;
                dp[row][col][form] = true;

                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
             cnt++;
        }
        return -1;
    }
