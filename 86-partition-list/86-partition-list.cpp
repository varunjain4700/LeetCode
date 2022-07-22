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
        ListNode* partition(ListNode *head, int x)
        {
            ListNode *temp = head;
            ListNode *head1 = NULL, *prev1 = NULL, *head2 = NULL, *prev2 = NULL;
            while (temp != NULL)
            {
                if (temp->val < x)
                {
                    if (!head1)
                        head1 = temp;
                    else
                        prev1->next = temp;
                    prev1 = temp;
                }
                else
                {
                    if (!head2)
                        head2 = temp;
                    else
                        prev2->next = temp;
                    prev2 = temp;
                }
                temp = temp->next;
            }
            if (prev2)
                prev2->next = NULL;
            if (prev1)
                prev1->next = head2;
            else
                return head2;
            return head1;
        }
};