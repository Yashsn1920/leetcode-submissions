/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void Parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &track){
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){ 
            TreeNode* curr = q.front(); 
            q.pop(); 
            if(curr -> left){ 
                track[curr -> left] = curr; 
                q.push(curr -> left);
            }
            if(curr -> right){ 
                track[curr -> right] = curr; 
                q.push(curr -> right); 
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> track; 
        Parents(root,track); 
        unordered_map<TreeNode*,bool> visit;
        queue<TreeNode*> q; 
        q.push(target);
        visit[target] = true;
        int level = 0; 
        
        while(!q.empty()){ 
            int size = q.size();
            if(level ++ == k){ 
                break; 
            }
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); 
                q.pop(); 
                if(curr -> left && !visit[curr -> left]){ 
                    q.push(curr -> left); 
                    visit[curr -> left] = true; 
                }
                if(curr -> right && !visit[curr -> right]){ 
                    q.push(curr -> right); 
                    visit[curr -> right] = true; 
                }
                if(track[curr] && !visit[track[curr]]){ 
                    q.push(track[curr]); 
                    visit[track[curr]] = true; 
                }
            }
        }
        vector<int> res; 
        while(!q.empty()){ 
            TreeNode* curr = q.front(); 
              q.pop(); 
            
            res.push_back(curr -> val); 

        }
        return res;
    }
};