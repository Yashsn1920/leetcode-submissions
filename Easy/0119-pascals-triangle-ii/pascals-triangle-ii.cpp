class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1}; 
        
            
            
            for(int i = 1; i <= rowIndex; i++){ 
                vector<int> row; 
                row.push_back(1); 
                for(int j = 0; j < ans.size() - 1; j++){ 
                    row.push_back(ans[j] + ans[j + 1]);
                    
                }
                row.push_back(1); 
                    
                ans = row;  
            }
        
        return ans;
    }
};