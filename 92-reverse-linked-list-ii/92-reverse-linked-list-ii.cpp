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
            ListNode *dummy = new ListNode();
            dummy->next = head;
            ListNode *temp = dummy;
            int cnt = 1;
            while (cnt != left)	//move the pointer to the starting node of the list which needs to be reversed
            {
                cnt++;
                temp = temp->next;
            }
            ListNode *start = temp;
            ListNode *prev = start->next;
            ListNode *curr = prev->next, *nxt = prev->next;
            cnt = 0;
            while (cnt != right - left)	//reverse the list
            {
                cnt++;
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            start->next->next = curr;
            start->next = prev;
            return dummy->next;
        }
};