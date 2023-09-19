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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto dummyHead = new ListNode();
        auto currentNode = dummyHead;
        auto minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>();

        for (auto list : lists)
        {
            while (list != nullptr)
            {
                minHeap.push(list->val);
                list = list->next;
            }
        }

        while (!minHeap.empty())
        {
            currentNode->next = new ListNode(minHeap.top());
            currentNode = currentNode->next;
            minHeap.pop();
        }
        return dummyHead->next;
    }
};