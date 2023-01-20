// Problem Link - https://leetcode.com/problems/house-robber-iii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,vector<int>>mp;
int helper(TreeNode* root,bool rob){
    if(!root)return 0;
    if(mp.count(root) && mp[root][rob]!=-1)return mp[root][rob];
    mp[root]={-1,-1};
    int cannotRob = helper(root->left,true)+helper(root->right,true);
    int canRob = rob?root->val+helper(root->left,false)+helper(root->right,false):-1;
    return mp[root][rob]=max(canRob,cannotRob);
}
    int rob(TreeNode* root) {
        return helper(root,true);
    }
};
