/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        auto toCheck = std:queue<std::pair<TreeNode*, TreeNode*>>{};
        toCheck.push({ p, q });

        while (!toCheck.empty())
        {
            auto [p, q] = toCheck.front();
            if (p && q)
            {
                if (p->val != q->val)
                {
                    return false;
                }

                toCheck.push({ p->right, q->right });
                toCheck.push({ p->left, q->left });
            }
            else if ((!p && q) || (p && !q))
            {
                return false;
            }
            toCheck.pop();
        }

        return true;
    }
};