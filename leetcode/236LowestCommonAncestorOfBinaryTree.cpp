/*
Runtime: 19 ms, faster than 65.82% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 14.2 MB, less than 87.03% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
*/
class Solution { 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }
        if (left)
            return left;
        else
            return right;
    }
};