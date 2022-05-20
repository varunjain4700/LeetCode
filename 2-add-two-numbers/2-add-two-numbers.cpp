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
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *dummy = new ListNode(0);
            ListNode *temp = dummy;
            int sum = 0, carry = 0;
            while (l1 || l2 || carry)
            {
                sum = 0;
                if (l1)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }
                sum += carry;
                ListNode *curr = new ListNode(sum % 10);
                temp->next = curr;
                temp = curr;
                if (sum >= 10)
                    carry = 1;
                else
                    carry = 0;
            }
            return dummy->next;
        }
};