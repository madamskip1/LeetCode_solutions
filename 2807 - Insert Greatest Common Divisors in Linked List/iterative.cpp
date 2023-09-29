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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto curNode = head;
        while (curNode && curNode->next)
        {
            auto nextNode = curNode->next;
            auto gcdValue = std::gcd(curNode->val, nextNode->val);
            curNode->next = new ListNode{ gcdValue, nextNode };
            curNode = nextNode;
        }
        return head;
    }
};