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
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }

        auto level{ 0 };
        auto queue = std::queue<TreeNode*>{};
        queue.push(root);

        while (!queue.empty())
        {
            ++level;
            auto sizeBefore = queue.size();
            for (std::size_t i = 0; i < sizeBefore; ++i)
            {
                auto node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
        }
        return level;
    }
};