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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
        {
            return true;
        }

        auto slowPointer{ head };
        auto fastPointer{ head };
        while (fastPointer && fastPointer->next)
        {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        if (fastPointer)
        {
            slowPointer = slowPointer->next;
        }

        ListNode* prev = nullptr;
        while (slowPointer)
        {
            auto tempNode = slowPointer->next;
            slowPointer->next = prev;
            prev = slowPointer;
            slowPointer = tempNode;
        }

        slowPointer = prev;
        auto slowPointer2 = head;
        while (slowPointer && slowPointer2)
        {
            if (slowPointer->val != slowPointer2->val)
            {
                return false;
            }
            slowPointer = slowPointer->next;
            slowPointer2 = slowPointer2->next;
        }

        return true;
    }
};