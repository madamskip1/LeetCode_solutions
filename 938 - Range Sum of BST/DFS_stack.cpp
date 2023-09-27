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
    int rangeSumBST(TreeNode* root, int low, int high) {
        auto stack = std::stack<TreeNode*>{};
        auto sum{ 0 };
        stack.push(root);

        while (!stack.empty())
        {
            auto node = stack.top();
            stack.pop();
            if (node)
            {
                auto val = node->val;
                if (val >= low && val <= high)
                {
                    sum += val;
                }
                stack.push(node->left);
                stack.push(node->right);
            }
        }

        return sum;
    }
};