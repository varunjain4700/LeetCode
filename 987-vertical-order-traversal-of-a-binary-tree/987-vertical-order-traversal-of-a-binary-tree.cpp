/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0] && a[1] == b[1])
                return a[2] < b[2];
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }
    vector<vector < int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({ root,
            { 0,
                0 } });
        vector<vector < int>> temp;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<TreeNode*, pair<int, int>> p = q.front();
                q.pop();
                TreeNode *node = p.first;
                int x = p.second.first, y = p.second.second;
                temp.push_back({ x,
                    y,
                    node->val });
                if (node->left)
                    q.push({ node->left,
                        {
                            x - 1,
                            y + 1
                        } });
                if (node->right)
                    q.push({ node->right,
                        {
                            x + 1,
                            y + 1
                        } });
            }
        }
        sort(temp.begin(), temp.end(), cmp);
        map<int, vector < int>> mp;
        for (int i = 0; i < temp.size(); i++)
        {
            mp[temp[i][0]].push_back(temp[i][2]);
        }
        vector<vector < int>> res;
        for (auto it: mp)
            res.push_back(it.second);
        return res;
    }
};