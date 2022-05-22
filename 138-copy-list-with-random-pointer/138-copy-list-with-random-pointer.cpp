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
            if (!head)
                return head;
            Node *temp = head, *nxt = head->next;
            while (temp != NULL)
            {
                nxt = temp->next;
                temp->next = new Node(temp->val);
                temp->next->next = nxt;
                temp = nxt;
            }

            temp = head;
            while (temp != NULL)
            {
                if (temp->random)
                    temp->next->random = temp->random->next;
                temp = temp->next->next;
            }
            Node *new_head = head->next;
            Node *curr = new_head;
            temp = head;
            while (temp != NULL)
            {
                temp->next = curr->next;
                temp = curr->next;
                if (temp)
                {
                    curr->next = temp->next;
                    curr = temp->next;
                }
            }
            return new_head;

           	// O(n) space

           	// Node *temp = head;
           	// map<Node*, Node*> mp;
           	// while (temp != NULL)
           	// {
           	//     Node *node = new Node(temp->val);
           	//     mp[temp] = node;
           	//     temp = temp->next;
           	// }
           	// temp = head;
           	// while (temp != NULL)
           	// {
           	//     mp[temp]->next = mp[temp->next];
           	//     mp[temp]->random = mp[temp->random];
           	//     temp = temp->next;
           	// }
           	// return mp[head];
        }
};