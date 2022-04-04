/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapNodes(ListNode *head, int k)
        {
            ListNode *temp = head;
            int cnt = k - 1;
            while (cnt > 0)
            {
                temp = temp->next;
                cnt--;
            }
            ListNode *node1 = temp;
            ListNode *node2 = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
                node2 = node2->next;
            }
            //cout<<node1->val<<" "<<node2->val<<endl;
            swap(node1->val, node2->val);
            return head;
        }
};