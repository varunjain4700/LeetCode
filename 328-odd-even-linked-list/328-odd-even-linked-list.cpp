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
        ListNode* oddEvenList(ListNode *head)
        {
            if (!head || !head->next)
                return head;
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *head2 = NULL;
            ListNode *temp1 = head, *temp2 = NULL;
            int cnt = 1;
            head = head->next;
            cnt++;
            while (head != NULL)
            {
                if (cnt % 2 == 0)
                {
                    if (temp2 == NULL)
                    {
                        head2 = temp2 = head;
                    }
                    else
                    {
                        temp2->next = head;
                        temp2 = head;
                    }
                }
                else
                {
                    temp1->next = head;
                    temp1 = head;
                }
                cnt++;
                head = head->next;
            }
            temp2->next = NULL;
            temp1->next = head2;
            return dummy->next;
        }
};