//https://leetcode.com/problems/house-robber-iii/description/
int helper(TreeNode* root,unordered_map<TreeNode*,int>& dp)
    {
         if(root==NULL)
         return 0;
         if(dp[root]!=0)
         return dp[root];
         int notpick = helper(root->left,dp)+helper(root->right,dp);
         int pick = root->val;
         if(root->left)
         pick += helper(root->left->left,dp)+helper(root->left->right,dp);
         if(root->right)
         pick += helper(root->right->left,dp)+helper(root->right->right,dp);
         return dp[root] = max(notpick,pick);
    }
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*,int> dp;
        return helper(root,dp);
    }
