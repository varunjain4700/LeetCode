/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        /*inorder traversal of bst gives nodes in sorted order so if we don't get th
        e nodes in sorted order it means 2 nodes are swapped.now there are 2 cases that can happen- 1) the nodes that need to be swapped are adjacent to each other  
        2)nodes are not adjacent
        we are maintaining a prev pointer which points to the previous node of the current node and if its val is less than the current node then it becomes a potential candidate to get swapped*/

        TreeNode * first;
    TreeNode * second;
    TreeNode * prev;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (first == NULL && root->val < prev->val)
            first = prev;
        if (first != NULL && root->val < prev->val)
            second = root;
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = NULL;
        second = NULL;
        prev = new TreeNode(INT_MIN);	//lowest node val given in constraint
        inorder(root);
        swap(first->val, second->val);
    }
};