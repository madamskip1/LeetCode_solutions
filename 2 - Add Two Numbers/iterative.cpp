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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* curNode = dummyHead;

        auto carryToNext{ 0 };

        while (l1 != nullptr && l2 != nullptr)
        {
            auto curSum = carryToNext;
            carryToNext = 0;

            curSum += l1->val;
            curSum += l2->val;
            l1 = l1->next;
            l2 = l2->next;

            if (curSum >= 10)
            {
                carryToNext = 1;
                curSum -= 10;
            }

            curNode->next = new ListNode(curSum);
            curNode = curNode->next;
        }

        while (l1 != nullptr)
        {
            auto curSum = carryToNext;
            carryToNext = 0;

            curSum += l1->val;
            l1 = l1->next;

            if (curSum >= 10)
            {
                carryToNext = 1;
                curSum -= 10;
            }

            curNode->next = new ListNode(curSum);
            curNode = curNode->next;
        }

        while (l2 != nullptr)
        {
            auto curSum = carryToNext;
            carryToNext = 0;

            curSum += l2->val;
            l2 = l2->next;

            if (curSum >= 10)
            {
                carryToNext = 1;
                curSum -= 10;
            }

            curNode->next = new ListNode(curSum);
            curNode = curNode->next;
        }

        if (carryToNext == 1)
        {
            curNode->next = new ListNode(carryToNext);
        }

        return dummyHead->next;
    }
};