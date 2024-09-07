//DAy 3 1367. Linked List in Binary Tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool checkCase(ListNode* listnode , TreeNode* treenode){

        if(!(listnode))
            return true;

        if (!treenode || listnode->val != treenode->val)
            return false;
        return (checkCase(listnode->next,treenode->right) || checkCase(listnode->next,treenode->left));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {

        if (!root)
            return false;
        
        if (checkCase(head, root)) return true;
        
        return (isSubPath(head, root->left) ||isSubPath(head, root->right));

    }
};