/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode * node2;
    void find_node(ListNode *head, int &k)
    {
        if (head == NULL)
            return;
        find_node(head->next, k);
        k--;
        if (k == 0)
            node2 = head;
    }
    ListNode* swapNodes(ListNode *head, int k)
    {
        ListNode *node1 = head;
        int cnt = k - 1;
        while (cnt > 0)
        {
            node1 = node1->next;
            cnt--;
        }
        find_node(head, k);
        swap(node1->val, node2->val);
        return head;
    }
};