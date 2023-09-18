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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }

        std::stack<TreeNode*> dfsStack;
        dfsStack.push(root);

        while (!dfsStack.empty())
        {
            auto curNode = dfsStack.top();
            dfsStack.pop();
            if (curNode)
            {
                std::swap(curNode->left, curNode->right);
                dfsStack.push(curNode->left);
                dfsStack.push(curNode->right);
            }
        }

        return root;
    }
};