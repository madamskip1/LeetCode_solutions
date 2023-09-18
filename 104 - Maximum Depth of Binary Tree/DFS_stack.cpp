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
        auto maxLevel{ 0 };
        auto depthStack = std::stack<std::pair<TreeNode*, int>>{};
        depthStack.push({ root, 1 });

        while (!depthStack.empty())
        {
            auto [curNode, depth] = depthStack.top();
            depthStack.pop();

            if (curNode)
            {
                maxLevel = std::max(maxLevel, depth);
                depthStack.push({ curNode->right, depth + 1 });
                depthStack.push({ curNode->left, depth + 1 });
            }
        }
        return maxLevel;
    }

};