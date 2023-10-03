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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* dummyHead = new ListNode();
        auto prev = dummyHead;
        auto current = head;
        while (current && current->next)
        {
            auto nextNode = current->next;
            auto afterNext = nextNode->next;

            current->next = afterNext;
            prev->next = nextNode;
            nextNode->next = current;
            prev = current;
            current = afterNext;
        }
        return dummyHead->next;
    }
};