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
    int heightleft(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int heightright(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left1 = heightleft(root);
        int right1 = heightright(root);

        if (left1 == right1) {
            return (1 << left1) - 1;
        }

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
