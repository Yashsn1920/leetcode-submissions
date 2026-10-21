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
    int sum1(TreeNode* root, int sum2){ 
        if(root == NULL){ 
            return 0;
        }
        int total = 0; 
       
        sum2 = sum2 * 10 + root -> val; 
        if(root -> left == NULL && root -> right == NULL){ 
           total = sum2;
        }
        total += sum1(root -> left,sum2); 
        total += sum1(root -> right, sum2); 
        
       
        return total; 
    }
public:
    int sumNumbers(TreeNode* root) {
       
        int ans = sum1(root,0); 
        return ans; 
    }
};