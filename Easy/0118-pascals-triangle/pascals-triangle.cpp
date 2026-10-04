class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> arr; 
        vector<vector<int>> ans; 
        if(numRows == 1){ 
            arr.push_back(1); 
            ans.push_back(arr); 
        }
        else{ 
            arr.push_back(1); 
            ans.push_back(arr); 
            
            for(int i = 2; i <= numRows;i++){ 
               vector<int>new1; 
                new1.push_back(1); 
                for(int j = 0; j < arr.size() - 1; j++){
                    new1.push_back(arr[j] + arr[j + 1]); 
                }
                new1.push_back(1); 
                arr = new1; 
                ans.push_back(arr); 
            }
        }
        return ans; 

        
    }
};