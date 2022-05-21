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
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *start = dummy;
            int counter = 1;
            while (counter != left)
            {
                start = start->next;
                head = head->next;
                counter++;
            }
            ListNode *copy = head;
            ListNode *prev = head, *next_node = head->next;
            counter++;
            head = head->next;
            while (counter <= right)
            {
                next_node = head->next;
                head->next = prev;
                prev = head;
                head = next_node;
                counter++;
            }
            start->next = prev;
            copy->next = head;
            return dummy->next;
        }
};