/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* merge(ListNode *l1, ListNode *l2)
        {
            ListNode *dummy = new ListNode(-1);
            ListNode *temp = dummy;
            while (l1 != NULL || l2 != NULL)
            {
                if (!l1)
                {
                    temp->next = l2;
                    break;
                }
                else if (!l2)
                {
                    temp->next = l1;
                    break;
                }
                else
                {
                    if (l1->val <= l2->val)
                    {
                        temp->next = l1;
                        temp = l1;
                        l1 = l1->next;
                    }
                    else
                    {
                        temp->next = l2;
                        temp = l2;
                        l2 = l2->next;
                    }
                }
            }
            return dummy->next;
        }
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];
        int i = 1;
        ListNode *head = lists[0];
        while (i < n)
        {
            head = merge(head, lists[i]);
            i++;
        }
        return head;
    }
};