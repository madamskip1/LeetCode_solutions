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
    void reorderList(ListNode* head) {
        if (!head->next)
        {
            return;
        }

        ListNode* rightPart = breakListAndReturnStartOfRightPart(head);
        rightPart = reverseList(rightPart);

        ListNode* nextNode;
        ListNode* nextRightNode;
        ListNode* curNode = head;

        while (rightPart)
        {
            nextRightNode = rightPart->next;
            nextNode = curNode->next;

            rightPart->next = nextNode;
            curNode->next = rightPart;

            rightPart = nextRightNode;
            curNode = nextNode;
        }
    }

    ListNode* breakListAndReturnStartOfRightPart(ListNode* head)
    {
        ListNode* slowIterator = head;
        ListNode* fastIterator = head->next;

        while (fastIterator && fastIterator->next)
        {
            slowIterator = slowIterator->next;
            fastIterator = fastIterator->next->next;
        }
        ListNode* startOfRight = slowIterator->next;
        slowIterator->next = NULL;

        return startOfRight;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head)
        {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* next;

        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};