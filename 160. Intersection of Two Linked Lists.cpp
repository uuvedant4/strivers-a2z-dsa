/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *dummy1 = headA;
        ListNode *dummy2 = headB;

        while (dummy1 != dummy2)
        {
            dummy1 = dummy1 ? dummy1->next : headB;
            dummy2 = dummy2 ? dummy2->next : headA;
        }

        return dummy1;
    }
};