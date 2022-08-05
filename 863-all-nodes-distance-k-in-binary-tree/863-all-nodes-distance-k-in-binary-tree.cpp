/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        void find_par(TreeNode *root, TreeNode *prev, map<TreeNode*, TreeNode*> &par)
        {
            if (!root)
                return;
            par[root] = prev;
            find_par(root->left, root, par);
            find_par(root->right, root, par);
        }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode*, TreeNode*> par;
        find_par(root, NULL, par);
        map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = 1;
        while (!q.empty())
        {
            if (k == 0)
                break;
            int sz = q.size();
            while (sz--)
            {
                TreeNode *node = q.front();
               	//cout<<node->val<<" ";
                q.pop();
                if (par[node] != NULL && !vis[par[node]])
                {
                    q.push(par[node]);
                    vis[par[node]] = 1;
                }
                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = 1;
                }
            }
           	// cout<<endl;
            k--;
        }
        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};