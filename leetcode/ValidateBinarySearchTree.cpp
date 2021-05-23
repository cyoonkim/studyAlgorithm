/*
Runtime: 12 ms, faster than 56.83% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 76.41% of C++ online submissions for Validate Binary Search Tree.
*/
class Solution {
public:
    
    bool isValidNode(TreeNode* root, long long low, long long high){
        if(root == nullptr)
            return true;
        if(root->val<high && root->val>low &&
           isValidNode(root->left,low,root->val) &&
           isValidNode(root->right,root->val,high)){
            return true;
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidNode(root,LONG_MIN,LONG_MAX);
    }
};