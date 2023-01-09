/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int idx = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            tmp = tmp->next;
            idx++;
        }

        idx = (idx / 2) + 1;
        ListNode *ans = head;
        while (idx > 1)
        {
            ans = ans->next;
            idx--;
        }

        return ans;
    }
};