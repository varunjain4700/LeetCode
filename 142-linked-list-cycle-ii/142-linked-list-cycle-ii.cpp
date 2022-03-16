/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeloop(ListNode *head, ListNode *ptr)
        {
            while (head != ptr)
            {
                head = head->next;
                ptr = ptr->next;
            }
            return ptr;
        }
    ListNode* detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return removeloop(head, slow);
            }
        }
        return NULL;
    }
};