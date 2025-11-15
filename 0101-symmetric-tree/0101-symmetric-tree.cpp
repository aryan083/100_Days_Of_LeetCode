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
    bool mirror(TreeNode* left1,TreeNode* right1){
        if(left1 == nullptr && right1 == nullptr)return true;
        
        if(left1 == nullptr || right1 == nullptr)return false;

        if(left1->val !=right1->val)return false;
        return mirror(left1->right,right1->left) && mirror(left1->left , right1->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return false;
        return mirror(root->left,root->right);
    }
};