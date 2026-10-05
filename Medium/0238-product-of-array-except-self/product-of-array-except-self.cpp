class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> ans(n);
        vector<int> leftarr(n);  
        vector<int> rightarr(n);  
        int left = 1;  
        int right = 1; 
        for(int i = 0; i < n; i++){ 
             leftarr[i] = left;
            left *= nums[i]; 
            
        }    
        for(int i = n - 1; i >= 0; i--){ 
            rightarr[i] = right;
            right *= nums[i]; 
           
        }
        for(int i = 0; i < n; i++){ 
            ans[i] = leftarr[i] * rightarr[i]; 
        }
        return ans;
    }
};