/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
    public:
        bool vis[101];
    map<int, Node*> mp;
    Node * head;
    void dfs(Node *src)
    {
        Node * temp;
        if (!vis[src->val])
        {
            temp = new Node(src->val);
            if (src->val == 1)
                head = temp;
            mp[src->val] = temp;
            vis[src->val] = 1;
        }
        for (auto child: src->neighbors)
        {
            if (!vis[child->val])
                dfs(child);
            mp[src->val]->neighbors.push_back(mp[child->val]);
        }
    }

    Node* cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        memset(vis, false, sizeof(vis));
        dfs(node);
        return head;
    }
};