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
       	//1->2->3->4->5
       	//1->2->3<-4 < -5
       	//1->2<-3 < -4
        bool isPalindrome(ListNode *head)
        {
            ListNode *slow = head, *fast = head;
            while (fast->next && fast->next->next)	//finding the middle of linked list
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            fast = slow->next;
            ListNode *prev = slow, *node = slow->next;
            slow = slow->next;
            prev->next = NULL;	//important to break this link
            while (slow != NULL)	//reversing the right part of the list
            {
                node = slow->next;
                slow->next = prev;
                prev = slow;
                slow = node;
            }
            while (head != NULL)	//moving head from the start and prev from last together
            {
                if (prev->val != head->val)
                    return false;
                head = head->next;
                prev = prev->next;
            }
            return true;
        }
};