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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fastIterator{ head };
        auto slowIterator{ head };

        for (int i = 0; i < n; ++i)
        {
            fastIterator = fastIterator->next;
        }

        if (!fastIterator)
        {
            return slowIterator->next;
        }

        while (fastIterator && fastIterator->next)
        {
            fastIterator = fastIterator->next;
            slowIterator = slowIterator->next;
        }

        if (slowIterator->next)
        {
            slowIterator->next = slowIterator->next->next;
        }

        return head;
    }
};