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
        curNode = dummyHead;

        carryToNext = 0;

        while (l1 != nullptr && l2 != nullptr)
        {
            auto curSum = carryToNext;
            carryToNext = 0;

            curSum += l1->val;
            curSum += l2->val;
            l1 = l1->next;
            l2 = l2->next;

            appendCurSumToList(curSum);
        }

        appendRestOfList(l1);
        appendRestOfList(l2);

        if (carryToNext == 1)
        {
            curNode->next = new ListNode(carryToNext);
        }

        return dummyHead->next;
    }

    void appendRestOfList(ListNode* list)
    {
        while (list != nullptr)
        {
            auto curSum = carryToNext;
            carryToNext = 0;

            curSum += list->val;
            list = list->next;

            appendCurSumToList(curSum);
        }
    }

    void appendCurSumToList(int curSum)
    {
        if (curSum >= 10)
        {
            carryToNext = 1;
            curSum -= 10;
        }

        curNode->next = new ListNode(curSum);
        curNode = curNode->next;
    }

private:
    int carryToNext;
    ListNode* curNode;
};