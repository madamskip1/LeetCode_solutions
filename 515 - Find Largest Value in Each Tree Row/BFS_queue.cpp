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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        auto answer = std::vector<int>{};
        auto BFS = std::queue<TreeNode*>{};
        BFS.push(root);

        while (!BFS.empty())
        {
            auto nodesThisLevel = BFS.size();
            auto maxValue{ INT_MIN };

            for (int i = 0; i < nodesThisLevel; ++i)
            {
                auto node = BFS.front();
                BFS.pop();
                maxValue = std::max(maxValue, node->val);
                if (node->left) BFS.push(node->left);
                if (node->right) BFS.push(node->right);
            }
            answer.push_back(maxValue);
        }

        return answer;
    }
};