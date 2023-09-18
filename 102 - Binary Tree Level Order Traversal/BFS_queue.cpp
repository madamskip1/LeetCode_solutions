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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto orderedValues = std::vector<vector<int>>();
        auto bfsQueue = std::queue<TreeNode*>();
        bfsQueue.push(root);

        while (!bfsQueue.empty())
        {
            auto levelValues = std::vector<int>();
            auto queueSize = bfsQueue.size();
            for (std::size_t i = 0; i < queueSize; ++i)
            {
                auto curNode = bfsQueue.front();
                if (curNode)
                {
                    levelValues.emplace_back(curNode->val);
                    bfsQueue.push(curNode->left);
                    bfsQueue.push(curNode->right);
                }
                bfsQueue.pop();
            }

            if (!levelValues.empty())
            {
                orderedValues.emplace_back(levelValues);
            }

        }

        return orderedValues;
    }
};