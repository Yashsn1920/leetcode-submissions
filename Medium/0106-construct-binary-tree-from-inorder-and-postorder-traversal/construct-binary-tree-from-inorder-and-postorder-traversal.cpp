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
    TreeNode* build(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend,const unordered_map<int,int>& inmap){ 
        if(poststart > postend || instart > inend){ 
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postend]); 
        int inroot = inmap.at(root -> val);
        int numsleft = inroot - instart;
        root -> left = build(postorder,poststart, poststart + numsleft - 1,inorder, instart, inroot - 1, inmap); 
        root -> right = build(postorder,poststart + numsleft ,postend - 1,inorder, inroot + 1, inend, inmap); 
        return root; 
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap; 
        for(int i = 0; i < inorder.size(); i++){ 
            inmap[inorder[i]] = i; 
        }
        return build(postorder,0, postorder.size() - 1, inorder, 0, inorder.size(), inmap);
    }
};