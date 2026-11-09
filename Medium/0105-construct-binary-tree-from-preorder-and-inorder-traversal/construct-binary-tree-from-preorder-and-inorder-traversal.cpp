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
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend,const unordered_map<int,int>& inmap){ 
        if(prestart > preend || instart > inend){ 
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]); 
        int inroot = inmap.at(root -> val);
        int numsleft = inroot - instart;
        root -> left = build(preorder,prestart + 1, prestart + numsleft,inorder, instart, inroot - 1, inmap); 
        root -> right = build(preorder, prestart + numsleft + 1, preend,inorder, inroot + 1, inend, inmap); 
        return root; 
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap; 
        for(int i = 0; i < inorder.size(); i++){ 
            inmap[inorder[i]] = i; 
        }
        return build(preorder,0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap); 
    }
};