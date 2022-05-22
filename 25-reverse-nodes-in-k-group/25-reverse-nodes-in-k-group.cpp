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
       	// Check this solution for explanation:
       	// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/183356/Java-O(n)-solution-with-super-detailed-explanation-and-illustration

       	//first iteration:
       	// dummy->1-->2-->3-->4-->5
       	// dummy-->1 < --2-->3-->4-->5
       	//start=dummy,tail=1,prev=2,curr=3;
       	// dummy-->2-->1-->3-->4-->5

       	//second iteration:
       	//dummy-->2-->1-->3 < --4-->5
       	// start=1,tail=3,prev=4,curr=5
       	//dummy-->2-->1-->4-->3-->5

        ListNode* reverseKGroup(ListNode *head, int k)
        {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *start = head;
            int len = 0;
            while (start != NULL)
            {
                len++;
                start = start->next;
            }
            start = dummy;
            ListNode *prev = head, *curr = head->next, *nxt = head->next;
            while (len >= k)
            {
                len -= k;
                int cnt = 0;
                while (cnt != k - 1)	//just reversing the list
                {
                    nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                    cnt++;
                }
               	//very important stuff going on in below lines
                ListNode *tail = start->next;
                tail->next = curr;
                start->next = prev;
                start = tail;

                prev = curr;
                if (curr)
                    curr = curr->next;
            }
            return dummy->next;
        }
};