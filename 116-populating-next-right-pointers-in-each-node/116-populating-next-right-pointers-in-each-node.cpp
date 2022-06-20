/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
    public:
        Node* connect(Node *root)
        {
            if (!root)
                return root;
           Node* start_node=root,*curr=NULL;
            while(start_node->left)
            {
                curr=start_node;
                while(curr) //traverse all nodes of current level
                {
                    if(curr->left)
                        curr->left->next=curr->right;
                    if(curr->right&&curr->next)
                        curr->right->next=curr->next->left;
                    curr=curr->next;
                }
                start_node=start_node->left;//move to next level
            }
            return root;
        }
};