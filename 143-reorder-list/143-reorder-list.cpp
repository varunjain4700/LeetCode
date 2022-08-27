/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        void reorderList(ListNode *head)
        {
            int len = 0;
            ListNode *temp = head;
            while (temp != NULL)
            {
                temp = temp->next;
                len++;
            }
            int counter = 0;
            temp = head;
            while (counter != len / 2)
            {
                temp = temp->next;
                counter++;
            }
            ListNode *prev = temp, *curr = temp->next, *nxt = temp->next;
            while (curr != NULL)
            {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *ptr1 = head, *ptr2 = prev;
            bool flag = 0;
            counter = 0;
            while (counter != len - 1)
            {
                if (!flag)
                {
                    temp = ptr1->next;
                    ptr1->next = ptr2;
                    ptr1 = temp;
                }
                else
                {
                    temp = ptr2->next;
                    ptr2->next = ptr1;
                    ptr2 = temp;
                }
                flag = !flag;
                counter++;
            }
            ptr1->next = NULL;
           	// return dummy->next;
        }
};