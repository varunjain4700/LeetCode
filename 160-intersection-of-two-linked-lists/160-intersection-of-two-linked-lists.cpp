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
        ListNode* getIntersectionNode(ListNode *head1, ListNode *head2)
        {
            ListNode *l1 = head1, *l2 = head2;
            int len1 = 0, len2 = 0;
            while (l1 != NULL)
            {
                l1 = l1->next;
                len1++;
            }
            while (l2 != NULL)
            {
                l2 = l2->next;
                len2++;
            }
            l1 = head1, l2 = head2;
            if (len2 > len1)
            {
                swap(l2, l1);
                swap(len1, len2);
            }
            int cnt = 0;
            while (cnt != len1 - len2)
            {
                l1 = l1->next;
                cnt++;
            }
            while (l1 && l2)
            {
                if (l1 == l2)
                    return l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            return l1;
        }
};