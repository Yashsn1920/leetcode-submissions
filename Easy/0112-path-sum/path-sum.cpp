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
    bool sum1(TreeNode* root, int targetSum,int sum){ 
        if(root == NULL){ 
            return false; 
        }
        sum += root -> val;
       
        if(root -> left == NULL && root -> right == NULL){ 
            return sum == targetSum; 
        }
        return sum1(root -> left, targetSum,sum) || sum1(root -> right, targetSum, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(sum1(root,targetSum,0) == true){ 
            return true; 
        }
        return false; 
        
    }
};