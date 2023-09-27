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
    TreeNode* searchBST(TreeNode* root, int val) {
        auto nextNode = root;

        while (nextNode)
        {
            if (nextNode->val < val)
            {
                nextNode = nextNode->right;
            }
            else if (nextNode->val > val)
            {
                nextNode = nextNode->left;
            }
            else
            {
                return nextNode;
            }
        }

        return NULL;
    }
};