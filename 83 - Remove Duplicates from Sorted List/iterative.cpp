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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        auto current = head->next;
        auto prevDistinct = head;
        prevDistinct->next = nullptr;

        while (current)
        {
            if (prevDistinct->val != current->val)
            {
                prevDistinct->next = current;
                prevDistinct = current;
                current = current->next;
                prevDistinct->next = nullptr;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};