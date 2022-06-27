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
        TreeNode* deleteNode(TreeNode *root, int key)
        {
            if (!root)
                return root;
            if (root->val == key)
            {
               	if (root->right)
               	{
               	    TreeNode *leftChild = root->left;
               	    TreeNode *temp = root->right;
               	    while (temp->left)
               	        temp = temp->left;
               	    temp->left = leftChild;
               	    root = root->right;	//important as need to send back the node which needs to be attached 
               	}
               	else
               	    root = root->left;

               	//either of the two ways will work
                // if (root->left)
                // {
                //     TreeNode *rightChild = root->right;
                //     TreeNode *temp = root->left;
                //     while (temp->right)
                //         temp = temp->right;
                //     temp->right = rightChild;
                //     root = root->left;
                // }
                // else
                //     root = root->right;
            }
            else if (root->val > key)
                root->left = deleteNode(root->left, key);
            else
                root->right = deleteNode(root->right, key);
            return root;
        }
};