#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int vector_size;
int preIdx = 0;

TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int inorder_start, int inorder_end) {
    if (inorder_start > inorder_end) {
        return nullptr;
    }

    TreeNode* rootNode = new TreeNode(preorder[preIdx]);
    if (inorder_start == inorder_end) {
        preIdx++;
        return rootNode;
    }

    int root_idx = find(inorder.begin(), inorder.end(), preorder[preIdx++]) - inorder.begin();
    rootNode->left = makeTree(preorder, inorder, inorder_start, root_idx - 1);
    rootNode->right = makeTree(preorder, inorder, root_idx + 1, inorder_end);
    
    return rootNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    vector_size = inorder.size();

    TreeNode* rootNode = makeTree(preorder, inorder, 0, vector_size-1);
    return rootNode;
}

int main(void) {
    vector<int> preorder = { 1,2 };
    vector<int> inorder = { 2,1 };

    TreeNode* return_value = buildTree(preorder, inorder);

	return 0;
}



