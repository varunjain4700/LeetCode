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
       	//Main observations:don't install cameras on leaf nodes and start putting cameras from bottom to top.
       	//  unordered_set<TreeNode*> covered;	//keeping a track of nodes that will be covered by the cameras
        int cameras = 0;
    int minCameraCover(TreeNode *root)
    {
        cameras = 0;
       	// covered.insert(NULL);	//for leaf nodes(as we don't want to install a camera on leaf node)
       	//solve(root, NULL);
        if (solve2(root) == 0)
            cameras++;
        return cameras;
    }
   	//0-->node is not covered by the camera
   	//1-->covered by the camera
   	//2-->has the camera itself
    int solve2(TreeNode *root)
    {
        if (!root)
            return 1;
        int left = solve2(root->left);
        int right = solve2(root->right);
        if (left == 0 || right == 0)
        {
            cameras++;
            return 2;
        }
        else if (left == 2 || right == 2)
            return 1;
        else return 0;
    }
    /*void solve(TreeNode *root, TreeNode *par)
    {
        if(!root)
            return;
        if (root)
        {
            solve(root->left, root);
            solve(root->right, root);
           	// traverse and reach to the bottom of tree
        }
        if ((!par && covered.find(root) == covered.end()) || covered.find(root->left) == covered.end() || covered.find(root->right) == covered.end())
        {
            cameras++;
            covered.insert(par);
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }*/
};