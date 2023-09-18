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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto newListDummyHead = new ListNode();
        auto newListCur = newListDummyHead;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                newListCur->next = list1;
                list1 = list1->next;
            }
            else
            {
                newListCur->next = list2;
                list2 = list2->next;
            }
            newListCur = newListCur->next;
        }

        if (list1)
        {
            newListCur->next = list1;
        }
        else
        {
            newListCur->next = list2;
        }

        return newListDummyHead->next;
    }
};