// Problem Link - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/


//Solution - 1

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
int ans;
int helper(TreeNode* root,int& sum){
    if(!root)
    return 0;
    sum+=root->val;
    return 1+helper(root->left,sum)+helper(root->right,sum);
}
void traversal(TreeNode* root){
    if(!root)
    return;
    int sum=0;
    int n = helper(root,sum);
    if(root->val==(sum/n))
    ans++;
    traversal(root->left);
    traversal(root->right);
}
    int averageOfSubtree(TreeNode* root) {
    ans=0;
    traversal(root);
    return ans;
    }
};



//Solution - 2


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
int ans=0;
pair<int,int> helper(TreeNode* root){
    if(!root)
    return {0,0};
    auto left = helper(root->left);
    int l_sum = left.first;
    int l_cnt = left.second;

    auto right = helper(root->right);
    int r_sum = right.first;
    int r_cnt = right.second;

    int sum = r_sum+l_sum+root->val;
    int n = r_cnt+l_cnt+1;
    if(root->val==(sum/n))
    ans++;
    return {sum,n};
}
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};
