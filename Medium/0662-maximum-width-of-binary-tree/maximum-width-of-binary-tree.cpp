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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){ 
            return 0; 
        }
        queue<pair<TreeNode*,int>>q;
        int ans = 0; 
        q.push({root,0}); 
        while(!q.empty()){ 
            int n = q.size(); 
            int min = q.front().second; 
            int first,last; 
            for(int i = 0; i < n; i++){ 
                long id = q.front().second - min; 
                TreeNode* root = q.front().first; 
                q.pop(); 
                if(i == 0){ 
                    first = id;
                }
                if(i == n - 1){ 
                    last = id; 
                }
                if(root -> left){ 
                    q.push({root -> left, 2 * id + 1}); 
                }
                if(root -> right){ 
                    q.push({root -> right, 2 * id + 2}); 
                }
            }
            ans = max(ans,last - first + 1); 
        }
        return ans;
        
    }
};