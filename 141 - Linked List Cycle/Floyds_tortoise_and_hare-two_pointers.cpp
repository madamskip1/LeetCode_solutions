/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Turtle and hare algorithm
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
        {
            return false;
        }

        auto slowIterator = head;
        auto fastIterator = head->next;

        while (fastIterator->next && fastIterator->next->next)
        {
            if (fastIterator == slowIterator)
            {
                return true;
            }
            slowIterator = slowIterator->next;
            fastIterator = fastIterator->next->next;
        }

        return false;
    }
};