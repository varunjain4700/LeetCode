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
        ListNode* rotateRight(ListNode *head, int k)
        {
            if(head==NULL)
                return NULL;
            int len = 0;
            ListNode *temp = head;
            while (temp != NULL)
            {
                temp = temp->next;
                len++;
            }
            k = k % len;
            if (k == 0)
                return head;
            ListNode *slow = head, *fast = head;
            for (int i = 0; i < k; i++)
                fast = fast->next;
            while (fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            temp = slow;
            slow = slow->next;
            temp->next = NULL;
            fast->next = head;
            head = slow;
            return head;
        }
};