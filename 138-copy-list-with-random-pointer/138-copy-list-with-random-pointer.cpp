/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            Node *temp = head;
            map<Node*, Node*> mp;
            while (temp != NULL)
            {
                Node *node = new Node(temp->val);
                mp[temp] = node;
                temp = temp->next;
            }
            temp = head;
            while (temp != NULL)
            {
                mp[temp]->next = mp[temp->next];
                mp[temp]->random = mp[temp->random];
                temp = temp->next;
            }
            return mp[head];
        }
};