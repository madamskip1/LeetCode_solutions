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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto result = std::vector<std::vector<int>>();

        if (!root)
        {
            return result;
        }

        bool rightToLeft = false;
        auto BFS = std::queue<TreeNode*>();
        BFS.push(root);

        while (!BFS.empty())
        {
            auto nodeThisLevel = BFS.size();
            auto valThisLevel = std::vector<int>();
            valThisLevel.reserve(nodeThisLevel);

            for (std::size_t i = 0; i < nodeThisLevel; ++i)
            {
                auto node = BFS.front();
                if (node)
                {
                    valThisLevel.push_back(node->val);
                    BFS.push(node->left);
                    BFS.push(node->right);
                }

                BFS.pop();
            }

            if (!valThisLevel.empty())
            {
                if (rightToLeft)
                {
                    std::reverse(valThisLevel.begin(), valThisLevel.end());
                }
                result.push_back(valThisLevel);
            }

            rightToLeft = !rightToLeft;
        }

        return result;
    }
};