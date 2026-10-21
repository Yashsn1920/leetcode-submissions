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
    vector<vector<int>> Sum1(TreeNode* root, int targetSum, int sum2,vector<int> &arr, vector<vector<int>> &ans ){ 
       
        if(root == NULL){
            return ans;
        }
    
        arr.push_back(root -> val); 
        sum2 = sum2 + root -> val; 
        if(root -> left == NULL && root -> right == NULL){ 
            if(sum2 == targetSum){ 
                ans.push_back(arr); 
            }
        }
        if(root -> left){ 
            Sum1(root -> left, targetSum,sum2,arr,ans); 
        }
         if(root -> right){ 
            Sum1(root -> right, targetSum,sum2,arr,ans); 
        }
        arr.pop_back(); 
        return ans; 
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr; 
        vector<vector<int>> res;
        Sum1(root, targetSum,0,arr,res); 
        return res; 
    }
};