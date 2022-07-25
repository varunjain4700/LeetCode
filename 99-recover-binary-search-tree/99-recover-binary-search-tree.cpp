/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode *first = NULL, *second = NULL;
    void inorder(TreeNode *root, TreeNode* &prev)
    {
        if (!root)
            return;
        inorder(root->left, prev);
       	//cout<<root->val<<" "<<prev->val<<endl;
        if (root->val < prev->val)
        {
            if (first == NULL)
            {
                first = prev;
                second = root;
            }
            else
                second = root;
        }
        prev = root;
        inorder(root->right, prev);
    }
    void recoverTree(TreeNode *root)
    {
        first = NULL;
        second = NULL;
        TreeNode *prev = new TreeNode(INT_MIN);
        inorder(root, prev);
        swap(first->val, second->val);
    }
};